#!/bin/sh

darkhttpd . \
--port 8082 \
	--mimetypes mime.txt \
	--header 'Cross-Origin-Opener-Policy: same-origin' \
	--header 'Cross-Origin-Embedder-Policy: require-corp'
