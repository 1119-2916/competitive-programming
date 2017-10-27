#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random
import sys

AI_NAME = "SampleAI.py"
width = 10
height = 16
packSize = 3
summation = 20
maxTurn = 500
OBSTACLE = summation + 1
EMPTY = 0
packs = []

def rot1(pack):
  rotated = [ [ 0 for i in range(packSize) ] for j in range(packSize) ]
  for i in range(packSize):
    for j in range(packSize):
      rotated[j][packSize - 1 - i] = pack[i][j]
  return rotated

def rotatePack(pack, rot):
  for _ in range(rot):
    pack = rot1(pack)
  return pack

def inputPack():
  pack = [ [ int(i) for i in input().split() ] for j in range(packSize) ]
  end = input()
  return pack

def initialInput():
  global width, height, packSize, summation, maxTurn, OBSTACLE
  width, height, packSize, summation, maxTurn = [ int(x) for x in input().split() ]
  OBSTACLE = summation + 1
  for _ in range(maxTurn):
    packs.append(inputPack())

def getFillObstaclePack(pack, obstacleNum):
  """
  1個だけpackをお邪魔で埋める
  """
  res = [ row[:] for row in pack ]
  for i in range(packSize):
    for j in range(packSize):
      if obstacleNum > 0 and res[i][j] == EMPTY:
        obstacleNum -= 1
        res[i][j] = OBSTACLE
  return res

def isValidFall(pack, x):
  """
  (回転済みの)packを座標xに落とせるならTrueを返す
  """
  for j in range(packSize):
    if x + j < 0 or width <= x + j:
      for i in range(packSize):
        if pack[i][j] != EMPTY:
          return False
  return True

def processTurn():
  turn = int(input())
  print("turn: " + str(turn), file=sys.stderr)
  remain_time = int(input())
  obstacleNum = int(input())
  board = [ [ int(i) for i in input().split() ] for j in range(height) ]
  end = input()

  enemyObstacleNum = int(input())
  enemyBoard = [ [ int(i) for i in input().split() ] for j in range(height) ]
  end = input()

  rot = random.randrange(0, 4)
  pack = getFillObstaclePack(packs[turn], obstacleNum)
  pack = rotatePack(pack, rot)

  left = -packSize + 1
  right = width
  while not isValidFall(pack, left): left += 1
  while not isValidFall(pack, right - 1): right -= 1
  col = random.randrange(left, right)
  return (col, rot)

def main():
  print(AI_NAME)
  sys.stdout.flush()

  random.seed(123456)
  initialInput()
  
  try:
    while True:
      x, rot = processTurn()
      print(x, rot)
      sys.stdout.flush()

  except Exception as e:
    print("error: {0}".format(e), file=sys.stderr)

if __name__ == '__main__':
  main()
