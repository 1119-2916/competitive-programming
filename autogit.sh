#!/bin/bash

git add -A;
today=$(date "+%Y-%m-%d");
git commit -m "${today}";
git push
