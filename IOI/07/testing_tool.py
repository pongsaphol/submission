""" Python script for local testing (compatible with both Python 2 and Python 3)
Disclaimer: this is a way to test your solutions, but it is NOT the real judging
system. The judging system behavior might be different.
"""
from __future__ import print_function
import random
import subprocess
import sys

def JudgePrint(p, s):
  # Print the judge output to your code's input stream. Log this interaction
  # to console (stdout) if PRINT_INTERACTION_HISTORY is True.
  print(s, file=p.stdin)
  p.stdin.flush()
  if PRINT_INTERACTION_HISTORY:
    print("Judge prints:", s)

"""Main function begins"""
# Retrieve the command to run your code from the arguments.
# If you cannot pass arguments to Python when running this testing tool, please
# replace sys.argv[1:] with the command list to run your code.
# e.g. C++ users: cmd = ["./my_binary"]
#      Python users: cmd = [sys.executable, "my_code.py"]
#      Java users: cmd = ["java", "my_main_class_name"]
cmd = sys.argv[1:]
assert cmd, "There should be at least one argument." + USAGE_MSG
if (cmd[0] == "-h") or (cmd[0] == "-help") or (cmd[0] == "--h") or (
    cmd[0] == "--help"):
  print(USAGE_MSG)
  sys.exit(0)

# Run your code in a separate process. You can debug your code by printing to
# stderr inside your code, or adding print statements in this testing tool.
# Note that your stderr output will be printed by this testing tool only after
# your code finishes, e.g. if your code hangs, you wouldn't get your stderr
# output.
try:
  p = subprocess.Popen(
      cmd,
      stdin=subprocess.PIPE,
      stdout=subprocess.PIPE,
      stderr=subprocess.PIPE,
      bufsize=1,
      universal_newlines=True)
except Exception as e:
  print("Failed to start running your code. Error:")
  print(e)
  sys.exit(-1)

call_count = 0
n, m = map(int, input().split())
x0, y0 = map(int, input().split())
x, y = map(int, input().split())
stra = str(n) + " " + str(x0) + " " + str(y0)
JudgePrint(p, stra)

def solve_ex(b, c):
  global call_count
  call_count += 1
  xx = x - m - m - m//2
  yy = y - m - m - m//2
  dx = b - xx
  dy = c - yy
  if dx < 0 or dy < 0 or dx >= 5*m or dy >= 5*m :
    return False
  dx = dx // m
  dy = dy // m
  if (dx + dy) % 2 == 0:
    return True
  else:
    return False

while True:
  inp = p.stdout.readline()
  a, b, c = inp.split()
  b = int(b)
  c = int(c)
  if a == "examine":
    if solve_ex(b, c):
      JudgePrint(p, "true")
    else:
      JudgePrint(p, "false")
  elif a == "debug":
    ret = "Debug " + str(b) + " " + str(c)
    print(ret)
  else:
    if b == x and c == y :
      print("Yes")
    else:
      print("No")
    sys.exit(-1)

