#!/usr/bin/python3

import sys
import math

def help_me():
    print("SYNOPSIS")
    print("\t./groundhog period")
    print("\nDESCRIPTION")
    print("\tperiod\tthe number of days defining a period")


def calcul_s(nbs, period):
    if (len(nbs) < period):
        return "nan"
    moy = sum(nbs[-period:]) / period
    i = 0
    tot = 0
    while i != period:
        tot += (nbs[len(nbs) - period + i] - moy)**2
        i += 1
    return format(round(math.sqrt(tot / period), 2), '0.2f')


def calcul_r(nbs, period):
    if (len(nbs) <= period):
        return "nan"
    a = nbs[len(nbs) - period - 1]
    if a == 0:
        return "man"
    b = round(((nbs[-1] - a) / a)* 100)
    return b


def calcul_g(nbs, period):
    if (len(nbs) <= period):
        return "nan"
    g = 0
    top = 0
    count = len(nbs) - period
    while count != len(nbs):
        top = nbs[count] - nbs[count-1]
        if (top < 0):
            top = 0
        g += top
        count += 1
    return format(round(g/period, 2), '0.2f')


def tell_them(a, b):
    print(a)
    exit(b)


def calcul_weird(nbs, period, s):
    if (len(nbs) <= period):
        return [nbs[-1], 0]
    size = len(nbs)
    diff = abs(nbs[size-1] - nbs[size-2])
    percent = diff / float(s)
    if (percent >= 2):
        percent = 0
    return [nbs[-1], round(percent, 2)]


def is_switch(nbs, period):
    if (len(nbs) <= period + 1):
        return ""
    try:
        a =  round((nbs[-1] / nbs[-1-period] - 1) * 100)
        b =  round((nbs[-2] / nbs[-2-period] - 1) * 100)
    except (ValueError, FloatingPointError, ZeroDivisionError, TypeError):
        return ""
    if (abs(a+b) != abs(b)+abs(a)):
        return "\ta switch occurs"
    return ""


def main(period):
    r = 0
    nbs = []
    switchs = 0
    weird = []

    try:
        inp = input()
    except (EOFError, KeyboardInterrupt):
        exit(84)

    while (inp != "STOP"):
        try:
            float(inp)
        except (ValueError, TypeError):
            tell_them("Is that a float nb ? ", 84)

        nbs.append(float(inp))
        g = calcul_g(nbs, period)
        r = calcul_r(nbs, period)
        txt = is_switch(nbs, period)
        s = calcul_s(nbs, period)
        weird.append(calcul_weird(nbs, period, s))
        if txt != "":
            switchs += 1
        print("g=" + str(g) + "\tr=" + str(r) + "%\ts="+ str(s) + txt)

        try:
            inp = input()
        except (EOFError, KeyboardInterrupt):
            exit(84)
    if (len(nbs) <= period):
        tell_them("Not enought numbers", 84)
    print('Global tendency switched {} times'.format(switchs))
    weird.sort(key = lambda x : x[1], reverse=True)
    weird = weird[:5]
    print("5 weirdest values are [{}, {}, {}, {}, {}]".format(weird[0][0], weird[1][0], weird[2][0], weird[3][0], weird[4 ][0]))
    exit(0)


if __name__ == '__main__':
    if (len(sys.argv) != 2):
        help_me()
        exit(84)

    if (sys.argv[1] == "-h"):
        help_me()
        exit(0)

    try:
        a = int(sys.argv[1])
    except ValueError:
        tell_them("Enter a valid nb ", 84)
    main(a)
