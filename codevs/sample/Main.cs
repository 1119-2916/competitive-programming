using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codevsStAI
{
    class Program
    {
        const string AI_NAME = "SampleAI.cs";
        const int EMPTY = 0;
        Random random = new Random(12345678);
        int turn = -1;

        int[][,] pack;

        int width;

        int height;

        int packSize;

        int summation;

        int obstacle;

        int maxTurn;

        long millitime;

        static void Main(string[] args)
        {
            new Program().run();
        }

        private string ReadLine()
        {
            for (;;)
            {
                string line = Console.ReadLine();
                if (line == null) throw new Exception("EOF");
                if (line.Trim().Length == 0) continue;
                return line;
            }
        }

        void println(string msg)
        {
            Console.WriteLine(msg);
            Console.Out.Flush();
        }

        void debug(string msg)
        {
            Console.Error.WriteLine(msg);
            Console.Error.Flush();
        }

        int[,] packRotate(int[,] pack, int rot)
        {
            int[,] res = copyPack(pack);
            for (int i = 0; i < rot; ++i)
                res = rot1(res);
            return res;
        }

        int[,] rot1(int[,] pack)
        {
            int[,] res = copyPack(pack);
            for (int i = 0; i < packSize; ++i)
                for (int j = 0; j < packSize; ++j)
                    res[j, packSize - i - 1] = pack[i, j];
            return res;
        }

        int[,] copyPack(int[,] pack)
        {
            return (int[,])pack.Clone();
        }

        int[,] fillObstaclePack(int[,] pack, int obstacleNum)
        {
            int[,] res = copyPack(pack);
            for (int i = 0; i < packSize; ++i)
                for (int j = 0; j < packSize; ++j)
                    if (obstacleNum > 0 && res[i, j] == EMPTY)
                    {
                        --obstacleNum;
                        res[i, j] = obstacle;
                    }
            return res;
        }

        bool isValidFall(int[,] pack, int x)
        {
            for (int j = 0; j < packSize; ++j)
                if (x + j < 0 || width <= x + j)
                    for (int i = 0; i < packSize; ++i)
                        if (pack[i, j] != EMPTY)
                            return false;
            return true;
        }


        void initialInput()
        {
            string[] inputStr = ReadLine().Split();
            width = int.Parse(inputStr[0]);
            height = int.Parse(inputStr[1]);
            packSize = int.Parse(inputStr[2]);
            summation = int.Parse(inputStr[3]);
            obstacle = summation + 1;
            maxTurn = int.Parse(inputStr[4]);
            pack = new int[maxTurn][,];
            for (int i = 0; i < maxTurn; ++i)
            {
                pack[i] = new int[packSize, packSize];
                for (int j = 0; j < packSize; ++j)
                {
                    String[] line = ReadLine().Split();
                    for (int k = 0; k < packSize; ++k)
                        pack[i][j, k] = int.Parse(line[k]);
                }
                string END = ReadLine();
            }
        }


        void run()
        {
            println(AI_NAME);
            initialInput();

            while (true)
            {
                turn = int.Parse(ReadLine());
                millitime = long.Parse(ReadLine());

                int obstacleNum = int.Parse(ReadLine());
                int[,] board = new int[height, width];
                for (int i = 0; i < height; ++i)
                {
                    string[] line = ReadLine().Split();
                    for (int j = 0; j < width; ++j)
                        board[i, j] = int.Parse(line[j]);
                }
                ReadLine();

                int enemyObstacleNum = int.Parse(ReadLine());
                int[,] enemyBoard = new int[height, width];
                for (int i = 0; i < height; ++i)
                {
                    string[] line = ReadLine().Split();
                    for (int j = 0; j < width; ++j)
                        board[i, j] = int.Parse(line[j]);
                }
                ReadLine();

                debug("turn : " + turn);

                int rot = random.Next(4);
                int[,] pack = fillObstaclePack(this.pack[turn], obstacleNum);
                pack = packRotate(pack, rot);
                int left = 0, right = width - packSize;
                left = -packSize + 1;
                right = width;
                while (!isValidFall(pack, left)) left++;
                while (!isValidFall(pack, right - 1)) right--;

                int col = random.Next(left, right);
                println(col + " " + rot);
            }
        }
    }
}

