import os
import socket
import threading
import time
import uuid

import requests
from flask import Flask, jsonify, request

app = Flask(__name__)

NODE_ID = str(uuid.uuid4())

# In Docker Compose, you can pass something like http://node-1:3000.
PEER_ADDRESS = os.getenv("PEER_ADDRESS", "")
BOOTSTRAP_URL = "http://bootstrap:5000"
REFRESH_SECONDS = 10

known_peers = set()


def add_peer(peer_url: str) -> bool:
    """Add a peer if it looks valid and is not this node."""
    if not peer_url:
        return False

    if peer_url == PEER_ADDRESS:
        return False

    if peer_url not in known_peers:
        known_peers.add(peer_url)
        return True

    return False


def register_with_bootstrap() -> None:
    """
    Register this node with the bootstrap node.
    """
    try:
        response = requests.post(
            f"{BOOTSTRAP_URL}/register",
            json={"peer": PEER_ADDRESS},
        )
        response.raise_for_status()
        print(f"Registered with bootstrap at {BOOTSTRAP_URL}")
    except requests.RequestException as exc:
        print(f"Bootstrap registration failed: {exc}")
        return


def peer_refresh_loop() -> None:
    """
    Background loop for peer discovery.
    """
    while True:
        try:
            response = requests.get(f"{BOOTSTRAP_URL}/peers")

            response.raise_for_status()

            data = response.json()

            for peer in data.get("peers", []):
                add_peer(peer)

        except requests.RequestException as exc:
            print(f"Could not refresh peers: {exc}")

        time.sleep(REFRESH_SECONDS)


@app.get("/")
def index():
    return jsonify({
        "message": f"Node {NODE_ID} is running!"
    })


@app.post("/message")
def receive_message():
    """
    Receive a message from a peer and store it in memory.
    """
    payload = request.get_json(silent=True) or {}

    sender = str(payload.get("sender", "unknown"))
    message = str(payload.get("msg", ""))

    print(f"Received message from {sender}: {message}")

    return jsonify({
        "status": "received"
    })


if __name__ == "__main__":
    register_with_bootstrap()

    thread = threading.Thread(target=peer_refresh_loop, daemon=True)
    thread.start()

    app.run(host="0.0.0.0", port=5000)
