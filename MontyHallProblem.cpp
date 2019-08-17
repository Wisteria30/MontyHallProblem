#include <bits/stdc++.h>
using namespace std;

int rand(int N, int noChoose1, int noChoose2, mt19937& mt) {
    if (noChoose1 == 1 && noChoose2 == 1) {
        uniform_int_distribution<int> dist(2, N);
        return dist(mt);
    } else if (noChoose1 == 1 && noChoose2 == N) {
        uniform_int_distribution<int> dist(2, N - 1);
        return dist(mt);
    } else if (noChoose1 == 1) {
        if (noChoose2 != 2) {
            uniform_int_distribution<int> dist(2, noChoose2 - 1);
            uniform_int_distribution<int> dist2(noChoose2 + 1, N);
            uniform_int_distribution<int> dist01(0, 1);
            return (dist01(mt) == 0 ? dist2(mt) : dist(mt));
        } else {
            uniform_int_distribution<int> dist(3, N);
            return dist(mt);
        }
    } else if (noChoose1 == N && noChoose2 == 1) {
        uniform_int_distribution<int> dist(2, N - 1);
        return dist(mt);
    } else if (noChoose1 == N && noChoose2 == N) {
        uniform_int_distribution<int> dist(1, N - 1);
        return dist(mt);
    } else if (noChoose1 == N) {
        if (noChoose2 != N - 1) {
            uniform_int_distribution<int> dist(1, noChoose2 - 1);
            uniform_int_distribution<int> dist2(noChoose2 + 1, N - 1);
            uniform_int_distribution<int> dist01(0, 1);
            return (dist01(mt) == 0 ? dist2(mt) : dist(mt));
        } else {
            uniform_int_distribution<int> dist(1, N - 2);
            return dist(mt);
        }
    } else if (noChoose2 == 1) {
        if (noChoose1 != 2) {
            uniform_int_distribution<int> dist(2, noChoose1 - 1);
            uniform_int_distribution<int> dist2(noChoose1 + 1, N);
            uniform_int_distribution<int> dist01(0, 1);
            return (dist01(mt) == 0 ? dist2(mt) : dist(mt));
        } else {
            uniform_int_distribution<int> dist(3, N);
            return dist(mt);
        }
    } else if (noChoose2 == N) {
        if (noChoose1 != N - 1) {
            uniform_int_distribution<int> dist(1, noChoose1 - 1);
            uniform_int_distribution<int> dist2(noChoose1 + 1, N - 1);
            uniform_int_distribution<int> dist01(0, 1);
            return (dist01(mt) == 0 ? dist2(mt) : dist(mt));
        } else {
            uniform_int_distribution<int> dist(1, N - 2);
            return dist(mt);
        }
    } else if (noChoose1 == noChoose2) {
        uniform_int_distribution<int> dist(1, noChoose1 - 1);
        uniform_int_distribution<int> dist2(noChoose1 + 1, N);
        uniform_int_distribution<int> dist01(0, 1);
        return (dist01(mt) == 0 ? dist2(mt) : dist(mt));
    } else if (noChoose1 < noChoose2) {
        if (noChoose1 + 1 != noChoose2) {
            uniform_int_distribution<int> dist(1, noChoose1 - 1);
            uniform_int_distribution<int> dist2(noChoose1 + 1, noChoose2 - 1);
            uniform_int_distribution<int> dist3(noChoose2 + 1, N);
            uniform_int_distribution<int> dist01(0, 2);
            int flag = dist01(mt);
            if (flag == 0)
                return dist(mt);
            else if (flag == 1)
                return dist2(mt);
            else
                return dist3(mt);
        } else {
            uniform_int_distribution<int> dist(1, noChoose1 - 1);
            uniform_int_distribution<int> dist2(noChoose2 + 1, N);
            uniform_int_distribution<int> dist01(0, 1);
            return (dist01(mt) == 0 ? dist2(mt) : dist(mt));
        }
    } else if (noChoose1 > noChoose2) {
        if (noChoose1 != noChoose2 + 1) {
            uniform_int_distribution<int> dist(1, noChoose2 - 1);
            uniform_int_distribution<int> dist2(noChoose2 + 1, noChoose1 - 1);
            uniform_int_distribution<int> dist3(noChoose1 + 1, N);
            uniform_int_distribution<int> dist01(0, 2);
            int flag = dist01(mt);
            if (flag == 0)
                return dist(mt);
            else if (flag == 1)
                return dist2(mt);
            else
                return dist3(mt);
        } else {
            uniform_int_distribution<int> dist(1, noChoose2 - 1);
            uniform_int_distribution<int> dist2(noChoose1 + 1, N);
            uniform_int_distribution<int> dist01(0, 1);
            return (dist01(mt) == 0 ? dist2(mt) : dist(mt));
        }
    } else {
        cout << "error" << endl;
        return -1;
    }
}

bool solve(int N, bool f, mt19937& mt) {
    uniform_int_distribution<int> dist(1, N);
    uniform_int_distribution<int> distLR(0, 1);

    int choose = dist(mt);
    int answer = dist(mt);

    // cout << "choose: " << choose << ", answer: " << answer << endl;

    // 扉を変更しなければそのまま確かめる
    if (!f) return (choose == answer);

    // 扉を変更する場合
    int openedDoor = rand(N, choose, answer, mt);
    choose = rand(N, choose, openedDoor, mt);
    // cout << "opendDoor: " << openedDoor << ", choose: " << choose << endl;
    return (choose == answer);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << "扉の数を整数で指定してください" << endl;
    int N;
    cin >> N;
    // 扉が2つ以下だと終了
    if (N < 3) return 0;

    cout << "何回試行しますか?" << endl;
    int cycle;
    cin >> cycle;
    cout << "一度選んだ扉を変更しますか?(する: 1, しない: 0)" << endl;
    bool flag;
    cin >> flag;
    double correct = 0;
    mt19937 mt{std::random_device{}()};
    for (int i = 0; i < cycle; i++) {
        if (solve(N, flag, mt)) correct++;
        if (i % (cycle / 10) == 0) {
            cout << "correct: " << correct << ", wrong: " << i + 1 - correct << endl;
        }
    }
    cout << "---------------------------------" << endl;
    cout << "---------------------------------" << endl;
    cout << "final" << endl;
    cout << "correct: " << correct << ", wrong: " << cycle - correct << endl;
    double acc = correct == 0 ? 0.0 : correct / cycle;
    double wro = (cycle - correct) == 0 ? 0.0 : (cycle - correct) / cycle;
    cout << "正解率: " << acc << ", 間違い率" << wro << endl;
}