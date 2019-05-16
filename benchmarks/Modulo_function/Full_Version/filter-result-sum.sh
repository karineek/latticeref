#!/bin/bash

awk '/ASSERTION(S)|SUBSTITUTED|identical|VERIFICATION|SUMMARY abstraction used|_mod#0|Aborted|UNKNOWN|Claim #/{
 print
}
{ a[++d]=$0}

{ a[++d]=$0}'


