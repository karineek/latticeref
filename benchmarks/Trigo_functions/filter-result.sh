#!/bin/bash

awk '/ASSERTION(S)|SUBSTITUTED|identical|VERIFICATION|Aborted|UNKNOWN/{
 print
}
{ a[++d]=$0}

{ a[++d]=$0}'


