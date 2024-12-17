#!/bin/bash
for i in $(seq 1 200); do
  ./client_uint32_t -H SHA224 -S c
done
