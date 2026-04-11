#!/bin/bash

for i in {1..5}; do
  curl -X POST http://localhost:500$(($i + 1))/message \
       -H "Content-Type: application/json" \
       -d "{\"sender\": \"Node$i\", \"msg\": \"Hello Node$(($i + 1))!\"}"
done