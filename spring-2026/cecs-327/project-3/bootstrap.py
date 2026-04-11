from flask import Flask, jsonify, request

app = Flask(__name__)

# The bootstrap node's main job is just to help nodes discover each other.
known_peers = set()


@app.get("/")
def index():
    return jsonify({
        "message": "Bootstrap node is running"
    })


@app.post("/register")
def register_peer():
    """
    Receive a node address and store it in memory.
    """
    payload = request.get_json(silent=True) or {}
    peer = str(payload.get("peer") or "")

    if not peer:
        return jsonify({
            "error": "Missing peer address"
        }), 400

    print(f"Registering peer: {peer}")

    known_peers.add(peer)

    return jsonify({
        "status": "registered", "peer": peer
    })


@app.get("/peers")
def get_peers():
    return jsonify({
        "peers": list(known_peers)
    })


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
