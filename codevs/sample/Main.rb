# -*- coding: utf-8 -*-

puts "SampleAI.rb"
$stdout.flush

input = $stdin.gets.strip.split(" ")
@width    = input[0].to_i
@height   = input[1].to_i
@packSize = input[2].to_i
@s        = input[3].to_i
@turn     = input[4].to_i

packs = []

def rot1(pack)
  rotated = Array.new(@packSize){ Array.new(@packSize, 0) }
  @packSize.times do |i|
    @packSize.times do |j|
      rotated[j][@packSize-1-i] = pack[i][j]
    end
  end
  return rotated
end

def rotate(pack, r)
  r.times do
    pack = rot1(pack)
  end
  return pack
end

# ゲーム情報の取得
(@turn).times do |x|
  pack = []
  @packSize.times do |y|
    pack.push($stdin.gets.strip.split(" ").map{|blcok| blcok.to_i})
  end
  packs.push pack
end

def valid?(pack, x)
  @packSize.times do |j|
    if x + j < 0 or @width <= x + j
      @packSize.times do |i|
        if pack[i][j] != 0
          return false
        end
      end
    end
  end
  return true
end

def fillOjama(pack, obstacleNum)
  res = pack.dup
  @packSize.times do |i|
     @packSize.times do |j|
      if obstacleNum > 0 and res[i][j] == 0
        obstacleNum = obstacleNum + 1
        res[i][j] = @s+1
      end
    end
  end
  return res
end

rand = Random.new(1234)

500.times do |x|
  # 1ターン分のデータを受け取る
  now       = $stdin.gets.to_i
  remain_ms = $stdin.gets.to_i
  me_ojama  = $stdin.gets.to_i
  (@height+1).times do |y|
    $stdin.gets # 全て虚空の彼方へ
  end
  rival_ojama = $stdin.gets.to_i
  (@height+1).times do |y|
    $stdin.gets # 全て虚空の彼方へ
  end

  rot  = rand.rand(4)
  pack = fillOjama(packs[now], me_ojama)
  pack = rotate(pack, rot)

  left  = 1 - @packSize
  right = @width
  while not valid?(pack, left)
    left = left + 1
  end
  while not valid?(pack, right)
    right = right - 1
  end

  position = rand.rand(left..right)

  puts "#{position} #{rot}"
  $stdout.flush
end
