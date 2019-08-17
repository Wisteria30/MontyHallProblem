import numpy as np
import sys


def solve(N, flag):
    doorList = np.array([i for i in range(N)])
    doorFlag = np.array([False for i in range(N)])
    doorFlag[np.random.randint(0, N)] = True
    choose = np.random.choice(doorList)
    if not flag:
        return doorFlag[choose]
    openList = np.array([i for i in doorList if not (doorFlag[i] or i == choose)])
    openDoor = np.random.choice(openList)
    doorFlag = np.delete(doorFlag, [openDoor, choose])
    return np.random.choice(doorFlag)


if __name__ == "__main__":
    print("扉の数を整数で指定してください")
    N = int(input())
    # 扉が2つ以下だと終了
    if N < 3:
        sys.exit()
    print("何回試行しますか?")
    cycle = int(input())
    print("一度選んだ扉を変更しますか?(する: 1, しない: 0)")
    flag = True if int(input()) == 1 else False
    correct = 0
    for i in range(1, cycle + 1):
        if solve(N, flag):
            correct += 1
        if i % (cycle // 10) == 0:
            print("正解数: {}, 不正解数: {}".format(correct, i - correct))

    print("---------------------------------")
    print("---------------------------------")
    print("final")
    print("正解数: {}, 不正解数: {}".format(correct, cycle - correct))
    acc = 0.0 if correct == 0 else (correct / cycle)
    wro = 0.0 if (cycle - correct) == 0 else ((cycle - correct) / cycle)
    print("正解率: {}, 間違い率: {}".format(acc, wro))
