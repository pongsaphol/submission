import collections
import math
import random

def odd(n):
    return bool(n & 1)


def ispp(s):
    return sum(odd(n) for n in collections.Counter(s).values()) <= 1


def naiveppcount(s):
    n = len(s)
    return sum(ispp(s[l:r + 1]) for l in range(n) for r in range(l, n))


def bit(c):
    return 1 << ((ord(c) - 1) & 31)


def neighbors(sig):
    yield sig
    for i in range(26):
        yield sig ^ (1 << i)


class PPCounter(object):
    def __init__(self):
        self.count = 0
        self._sigcount = collections.Counter({0: 1})
        self._leftsig = 0
        self._rightsig = 0

    def pushleft(self, c):
        self._leftsig ^= bit(c)
        for sig in neighbors(self._leftsig):
            self.count += self._sigcount[sig]
        self._sigcount[self._leftsig] += 1

    def popleft(self, c):
        self._sigcount[self._leftsig] -= 1
        for sig in neighbors(self._leftsig):
            self.count -= self._sigcount[sig]
        self._leftsig ^= bit(c)

    def pushright(self, c):
        self._rightsig ^= bit(c)
        for sig in neighbors(self._rightsig):
            self.count += self._sigcount[sig]
        self._sigcount[self._rightsig] += 1

    def popright(self, c):
        self._sigcount[self._rightsig] -= 1
        for sig in neighbors(self._rightsig):
            self.count -= self._sigcount[sig]
        self._rightsig ^= bit(c)


def ppcount(s, intervals):
    sqrtn = int(math.sqrt(len(s)))
    intervals = sorted(
        intervals, key=lambda interval: (interval[0] // sqrtn, interval[1]))
    l = 0
    r = -1
    ctr = PPCounter()
    for interval in intervals:
        il, ir = interval
        while l > il:
            l -= 1
            ctr.pushleft(s[l])
        while r < ir:
            r += 1
            ctr.pushright(s[r])
        while l < il:
            ctr.popleft(s[l])
            l += 1
        while r > ir:
            ctr.popright(s[r])
            r -= 1
        yield interval, ctr.count

n = int(input())
s = input()
m = int(input())
intervals = []
for i in range(m):
    l, r = map(int, input().split())
    l = l - 1
    r = r - 1
    intervals.append((min(l, r), max(l, r)))
for (l, r), count in ppcount(s, intervals):
    print(count)

