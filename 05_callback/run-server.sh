#!/bin/sh

darkhttpd . \
	--mimetypes mime.txt \
	--header 'Cross-Origin-Opener-Policy: same-origin' \
	--header 'Cross-Origin-Embedder-Policy: require-corp'
