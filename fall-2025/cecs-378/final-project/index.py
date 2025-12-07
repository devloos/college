from http.server import SimpleHTTPRequestHandler, HTTPServer


class CustomHandler(SimpleHTTPRequestHandler):
    def end_headers(self):
        # Add any headers you want:
        self.send_header("Content-Security-Policy", "script-src 'self'")
        self.send_header("X-Content-Type-Options", "nosniff")
        super().end_headers()


HTTPServer(("localhost", 8080), CustomHandler).serve_forever()
