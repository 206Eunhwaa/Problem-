#include <iostream>
#include <string>
#include <vector>
using namespace std;

// =========== BAI 1 ===========
string next_str(string s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] < 'c') { s[i]++; return s; }
        s[i] = 'a';
    }
    return string(s.size() + 1, 'a');
}

// =========== BAI 2 ===========
string prev_str(string s) {
    if (s == "a") return "";
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] > 'a') { s[i]--; return s; }
        s[i] = 'c';
    }
    return string(s.size() - 1, 'c');
}

// =========== BAI 3 ===========
long long pw3(int n) {
    long long r = 1;
    for (int i = 0; i < n; i++) r *= 3;
    return r;
}

long long rank_s(string s) {
    long long r = 0, base = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        r += (s[i] - 'a') * base;
        base *= 3;
    }
    return r;
}

long long count_after(string s) {
    return pw3(s.size()) - 1 - rank_s(s);
}

// =========== BAI 4 ===========
long long count_contain(int n, string s) {
    int m = s.size();
    if (n < m) return 0;

    vector<int> f(m, 0);
    for (int i = 1; i < m; i++) {
        int j = f[i - 1];
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) j++;
        f[i] = j;
    }

    vector<vector<int>> go(m + 1, vector<int>(3));
    for (int st = 0; st <= m; st++)
        for (int c = 0; c < 3; c++) {
            if (st == m) { go[st][c] = m; continue; }
            int j = st;
            while (j > 0 && 'a' + c != s[j]) j = f[j - 1];
            if ('a' + c == s[j]) j++;
            go[st][c] = j;
        }

    vector<long long> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<long long> ndp(m + 1, 0);
        for (int st = 0; st <= m; st++)
            for (int c = 0; c < 3; c++)
                ndp[go[st][c]] += dp[st];
        dp = ndp;
    }

    long long no = 0;
    for (int st = 0; st < m; st++) no += dp[st];
    return pw3(n) - no;
}

// =========== MAIN ===========
int main() {
    // --- Test case bai 1: next(s) ---
    cout << "=== Bai 1: next(s) ===" << endl;
    cout << "next(abc)  = " << next_str("abc") << " (mong doi: aca)" << endl;
    cout << "next(bccc) = " << next_str("bccc") << " (mong doi: caaa)" << endl;
    cout << "next(ccc)  = " << next_str("ccc") << " (mong doi: aaaa)" << endl;

    // --- Test case bai 2: previous(s) ---
    cout << "\n=== Bai 2: previous(s) ===" << endl;
    cout << "previous(aca)  = " << prev_str("aca") << " (mong doi: abcc)" << endl;
    cout << "previous(caaa) = " << prev_str("caaa") << " (mong doi: bccc)" << endl;
    string p = prev_str("a");
    cout << "previous(a)    = " << (p.empty() ? "(none)" : p) << " (mong doi: none)" << endl;

    // --- Test case bai 3: count_after(s) ---
    cout << "\n=== Bai 3: count_after(s) ===" << endl;
    cout << "count_after(aaa) = " << count_after("aaa") << " (mong doi: 26)" << endl;
    cout << "count_after(abc) = " << count_after("abc") << " (mong doi: 21)" << endl;
    cout << "count_after(ccc) = " << count_after("ccc") << " (mong doi: 0)" << endl;

    // --- Test case bai 4: count_contain(n, s) ---
    cout << "\n=== Bai 4: count_contain(n, s) ===" << endl;
    cout << "count_contain(3, ab) = " << count_contain(3, "ab") << " (mong doi: 6)" << endl;
    cout << "count_contain(4, ab) = " << count_contain(4, "ab") << " (mong doi: 26)" << endl;
    cout << "count_contain(4, abc)= " << count_contain(4, "abc") << " (mong doi: 6)" << endl;

    return 0;
}