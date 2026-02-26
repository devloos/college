# UDP Client-Server with Docker

A simple UDP server and client communicating over a Docker network.

## Run

```bash
docker compose up --build --scale client=3
```

This starts 1 server and 3 clients. Each client sends 5 messages to the server and the server logs everything it receives.

## Stop

```bash
docker compose down
```
