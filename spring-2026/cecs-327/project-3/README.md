# P2P System

## Files

- `bootstrap.py`: central registry for initial peer discovery
- `node.py`: one peer node that can register, discover peers, and receive messages
- `Dockerfile`: builds the peer node image
- `bootstrap.Dockerfile`: builds the bootstrap image
- `docker-compose.yml`: starts one bootstrap and two peers

## Quick Start

Build and run:

```bash
docker compose up --build
```

In another terminal, test the services:

```bash
curl http://localhost:5000/peers
curl http://localhost:5001/
curl http://localhost:5002/
```

Send test messages:

```bash
chmod +x test-messages.sh
./test-messages.sh
```
