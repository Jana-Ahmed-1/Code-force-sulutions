// 1.
// //                               Problem: 2167C – Isamatdin and His Magic Wand
// C. Isamatdin and His Magic Wand!
// time limit per test2 seconds
// memory limit per test256 megabytes
// Isamatdin has n
//  toys arranged in a row. The i
// -th toy has an integer ai
// . He wanted to sort them because otherwise, his mother would scold him.

// However, Isamatdin never liked arranging toys in order, so his friend JahonaliX gave him a magic wand to help. Unfortunately, JahonaliX made a small mistake while creating the wand.

// But Isamatdin couldn't wait any longer and decided to use the broken wand anyway. The wand can only swap two toys if their integers have different parity (one is even, the other is odd). In other words, you can swap toys in positions (i,j)
//  only if aimod2≠ajmod2
// , where mod
//  — is the remainder of integer division.

// Now he wants to know the lexicographically smallest∗
//  arrangement he can achieve using this broken wand.

// ∗
// A sequence p
//  is lexicographically smaller than a sequence q
//  if there exists an index i
//  such that pj=qj
//  for all j<i
// , and pi<qi
// .

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (1≤n≤2⋅105
// ) — the number of toys.

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤109
// ) — the integers of the toys.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output n
//  integers — the lexicographically smallest sequence that can be obtained using the described operation.

// Example
// InputCopy
// 7
// 4
// 2 3 1 4
// 5
// 3 2 1 3 4
// 4
// 3 7 5 1
// 2
// 1000000000 2
// 3
// 1 3 5
// 5
// 2 5 3 1 7
// 4
// 2 4 8 6
// OutputCopy
// 1 2 3 4 
// 1 2 3 3 4 
// 3 7 5 1 
// 1000000000 2 
// 1 3 5 
// 1 2 3 5 7 
// 2 4 8 6 
// Note
// In the first test case, we can swap positions (1,3)
//  and then (2,3)
// .

// In the second test case, we can swap positions (1,2)
// , (1,3)
// , and then (2,3)
// .

// In the third and fourth test cases, we can't swap any positions because all toy integers have the same parity.



#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<long long> evens, odds;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) evens.push_back(a[i]);
            else odds.push_back(a[i]);
        }

        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());

        int ei = 0, oi = 0;
        vector<long long> ans(n);

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) ans[i] = evens[ei++];
            else ans[i] = odds[oi++];
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i];
            if (i + 1 < n) cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}


// 2.
//                                                  A. ASCII Art Contest
// time limit per test1 second
// memory limit per test256 megabytes
// Three leading AI-powered creative assistants—Gemini, ChatGPT, and Claude—enter the first ever ASCII Art Contest, where they must impress a panel of human judges with their text-based masterpieces.

// Each participant receives a score between 80 and 100 (inclusive). The organizers want to announce the final standing only if the judges' opinions are "close enough"; otherwise, they will ask the judges to reconsider.

// Given the three integer scores of Gemini, ChatGPT, and Claude, determine the contest result:

// If the maximum score and the minimum score differ by at least 10 points, print check again (the judging seems inconsistent, so the panel must re-evaluate).
// Otherwise, print final X, where X is the median of the three scores (the score that would be in the middle if all three were sorted in non-decreasing order).
// Input
// A single line contains three integers g,c,ℓ
// , representing the scores of Gemini, ChatGPT, and Claude respectively.

// 80≤g,c,ℓ≤100
// Output
// Print the required answer in a line.

// Examples
// Input
// 88 94 95
// Output
// final 94
// Input
// 100 80 81
// Output
// check again
// Input
// 98 99 98
// Output
// final 98
// Input
// 95 86 85
// Output
// check again

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g, c, l;
    cin >> g >> c >> l;

    int mx = max(g, max(c, l));
    int mn = min(g, min(c, l));

    if (mx - mn >= 10) {
        cout << "check again\n";
    } else {
        int a[3] = {g, c, l};
        sort(a, a + 3);
        cout << "final " << a[1] << "\n";
    }

    return 0;
}


// 3.
//                                                    B. Your Name
// time limit per test1 second
// memory limit per test256 megabytes
// khba is writing his girlfriend's name. He has n
//  cubes, each with one lowercase Latin letter written on it. They are arranged in a row, forming a string s
// . His girlfriend's name is also a string t
// , consisting of n
//  lowercase Latin letters.

// To prove his love, he must check whether it is possible to rearrange the letters of string s
//  so that it becomes her name t
// .

// Input
// The first line contains an integer q
//  (1≤q≤1000
// ) — the number of test cases.

// The first line of each test case contains an integer n
//  (1≤n≤20
// ).

// The second line of each test case contains two distinct strings s
//  and t
// , each consisting of n
//  lowercase Latin letters.

// Output
// For each test case, output "YES" if the letters of s
//  can be arranged to form t
// ; otherwise, output "NO".

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as positive responses.

// Example
// Input
// 5
// 7
// humitsa mitsuha
// 4
// orhi hori
// 6
// aakima makima
// 6
// nezuqo nezuko
// 6
// misaka mikasa
// OutputCopy
// YES
// YES
// NO
// NO
// YES
// Note
// In the first example, the initial string is "humitsa", and the following operations can be performed:

// swap the first and third characters, resulting in "muhitsa"
// swap the second and fourth characters, resulting in "mihutsa"
// swap the third and fifth characters, resulting in "mithusa"
// swap the fourth and sixth characters, resulting in "mitsuha"
// In the second example, the initial string is "orhi", and the following operations can be performed:

// swap the second and third characters, resulting in "ohri"
// swap the first and second characters, resulting in "hori"

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

// 4.
//                                                      A. Same Difference
// time limit per test1 second
// memory limit per test256 megabytes

// You are given a string s
//  of length n
// , consisting of lowercase letters.

// In one operation, you can select an integer i
//  such that 1≤i<n
//  and change si
//  into si+1
// .

// What is the minimum number of operations needed to make every character the same? It can be proved that this is always possible.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤20
// ). The description of the test cases follows.

// The first line of each test case contains an integer n
//  (2≤n≤100
// ) — the length of the string.

// The following line contains a string s
//  of length n
// , consisting of lowercase letters.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 100
// .

// Output
// For each test case, output a single integer — the minimum number of operations needed to make every character the same.

// Example
// Input
// 5
// 3
// qwq
// 2
// aa
// 4
// test
// 5
// abbac
// 6
// abcabc
// Output
// 1
// 0
// 2
// 4
// 4
// Note
// In the first test case, you can change s2
//  to s3
//  using 1
//  operation to reach the goal.

// In the third test case, you can change s3
//  to s4
//  and then change s2
//  to s3
// , using 2
//  operations in total. It can be proved that the answer is not less than 2
// .

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        char last = s[n-1];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != last)
                cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}

// 5.
//                                                  A. Sequence Game
// time limit per test1 second
// memory limit per test256 megabytes
// Given an integer sequence of length n
//  denoted as a1,a2,…,an
//  and an integer x
// .

// You can perform the following operation: select two adjacent numbers ai
//  and ai+1
//  and replace them with an integer y
// , which satisfies min(ai,ai+1)≤y≤max(ai,ai+1)
// . After the replacement, the original ai
//  and ai+1
//  are removed from the sequence, and the elements are renumbered from 1
//  to n−1
// .

// For example, for a=[1,2,4,5]
//  you can select a2=2
//  and a3=4
// , and replace them with 3
// . After that, a
//  becomes [1,3,5]
// . However, you cannot select a1=1
//  and a2=2
//  and replace them with 3
//  (since y
//  is bigger than max(ai,ai+1)
// , nor can you select a1=1
//  and a3=4
//  (the selected numbers should be adjacent).

// Clearly, after performing n−1
//  operations, only one number will remain. The question is whether this final number can be exactly equal to x
// .

// Input
// Each test contains multiple test cases. The first line contains the number of test cases T
//  (1≤T≤500
// ). The description of the test cases follows.

// The first line of each test case contains one integer n
//  (1≤n≤100
// ).

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (−109≤ai≤109
// ).

// The third line of each test case contains one integer x
//  (−109≤x≤109
// ).

// Output
// For each test case, output "YES" (without quotes) if the final number can be exactly equal to x
// , and "NO" otherwise.

// You can output "YES" and "NO" in any case (for example, strings "yES", "yes" and "Yes" will be recognized as a positive response).

// Example
// Input
// 3
// 3
// 2 7 5
// 4
// 5
// -1 3 7 -9 -2
// 8
// 6
// 1 -1 -4 5 1 -4
// -2
// Output
// YES
// NO
// YES
// Note
// In the first test case, you can first select a2=7
//  and a3=5
// , and replace them with 6
// . After that, a
//  becomes [2,6]
// . Now you can select a1=2
//  and a2=6
// , and replace them with 4
// .

// In the second test case, it can be shown that the final number can never be 8
// .

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long x;
        cin >> x;

        long long mn = *min_element(a.begin(), a.end());
        long long mx = *max_element(a.begin(), a.end());

        if (mn <= x && x <= mx) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}


// 6.
//                                                     A. Beautiful Average
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an array a
//  of length n
// .

// Your task is to find the maximum possible average value of any subarray∗
//  of the array a
// .

// Formally, for any indices l,r
//  such that 1≤l≤r≤n
// , define the average of the subarray al,al+1,…,ar
//  as the sum of elements divided by the number of elements or:
// avg(l,r)=1r−l+1∑i=lrai
// Output the maximum value of avg(l,r)
//  over all choices of l,r
// .

// ∗
// An array b
//  is a subarray of an array a
//  if b
//  can be obtained from a
//  by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. In particular, an array is a subarray of itself.

// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of test cases.

// The first line of each testcase contains a single integer n
//  (1≤n≤10
// ) — the length of the array a
// .

// The second line of each testcase contains n
//  integers a1,a2,…,an
//  (1≤ai≤10
// ) — the elements of the array.

// Output
// For each testcase, output a single integer — the maximum average of any subarray of the given array.

// It can be shown that the answer is always an integer.

// Example
// Input
// 3
// 4
// 3 3 3 3
// 5
// 7 1 6 9 9
// 5
// 3 4 4 4 3
// Output
// 3
// 9
// 4

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int mx = *max_element(a.begin(), a.end());
        cout << mx << "\n";
    }

    return 0;
}


// 7.
//                                                       A. Round Trip
// time limit per test1 second
// memory limit per test512 megabytes
// They say that if you do 1000 rounds, there's a secret cartoon in the end (c)
// Petya and Vasya love participating in Codeforces contests. Vasya made a bet with Petya that he will take part in more rated rounds than him. Initially, Vasya's rating is R0
// . There will be n
//  rounds conducted in total, each of one of two types:

// div. 1 — rated for all participants
// div. 2 — rated for participants with rating strictly less than X
// , and unrated for all others,
// In an unrated round, Vasya cannot change his rating. If Vasya's rating before a rated round was R
// , then for any non-negative integer x
//  between R−D
//  and R+D
//  (inclusive) Vasya can adopt a strategy such that his rating becomes exactly x
//  afterwards (here D
//  is a positive integer). Note that rating may never become negative.

// Help Vasya determine the maximum number of rated rounds he can participate in.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤1000
// ). The description of the test cases follows.

// The first line of each test case contains four integers: R0,X,D,n
//  (0≤R0≤109
// , 1≤X≤109
// , 1≤D,n≤1000
// ) — Vasya's initial rating, the rating threshold between divisions, the maximum rating delta, and the number of rounds.

// The second line of each test case contains a string of size n
// . The string will only contain the characters "1" and "2", representing div. 1 and div. 2 rounds respectively.

// The sum of n
//  across all test cases does not exceed 3⋅104
// .

// Output
// For each test case, print a single integer — the maximum number of rated rounds Vasya can participate in.

// Example
// Input
// 4
// 2100 2100 5 3
// 222
// 2098 2100 5 6
// 111211
// 2115 2100 226 7
// 2211121
// 0 10 4 8
// 22111121
// Output
// 0
// 6
// 5
// 8
// Note
// In the first example, since R0≥X
// , each div. 2 round is unrated for Vasya, so his rating never changes. Therefore, he cannot make any round rated for himself, and the answer is 0
// .

// In the second example, one of the optimal sequences of ratings after each round is: 2098→2103→2101→2099→2097→2097→2092
// .

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long R0, X, D;
        int n;
        cin >> R0 >> X >> D >> n;
        string s;
        cin >> s;

        long long L = R0, R = R0;
        int ans = 0;

        for (char c : s) {
            if (c == '1') {
                L = max(0LL, L - D);
                R = R + D;
                ans++;
            } else { // '2'
                if (L < X) {
                    long long Rr = min(R, X - 1);
                    if (Rr >= L) {
                        L = max(0LL, L - D);
                        R = Rr + D;
                        ans++;
                    }
                } else {
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}


8.
//                                                        A. Pizza Time
// time limit per test1 second
// memory limit per test256 megabytes

// Hao and Alex are good friends. After winning a coding competition together, they received a huge pizza as their prize.

// Initially, they are given n
//  slices of pizza. Each day, the following process takes place:

// If there are at most 2
//  slices remaining, Alex eats all of them.
// Otherwise, let m
//  be the current number of slices (m≥3
// ). Hao splits them into three groups of sizes m1
// , m2
// , and m3
//  such that:
// m1+m2+m3=m and 1≤m1≤m2≤m3.

// Then:

// Hao eats m1
//  slices (the smallest group).
// Alex eats m2
//  slices (the middle group).
// The remaining m3
//  slices (the largest group) are carried over to the next day.
// Your task is to determine the maximum total number of slices Hao can eat if he always chooses the partition optimally.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤500
// ). The description of the test cases follows.

// The first and only line of each test case contains a single integer n
//  (3≤n≤109
// ) — the initial number of pizza slices.

// Note that there are no constraints on the sum of n
//  over all test cases.

// Output
// For each test case, output a single integer representing the maximum total number of slices Hao can eat.

// Example
// Input
// 3
// 8
// 4
// 3
// Output
// 3
// 1
// 1
// Note
// In the first test case, Hao can eat 3
//  slices as follows:

// Split into m1=2
// , m2=3
// , and m3=3
// . Hao eats 2
//  slices, Alex eats 3
//  slices, and the remaining 3
//  slices are carried over to the next day.
// Split into m1=1
// , m2=1
// , and m3=1
// . Hao eats 1
//  slice, Alex eats 1
//  slice, and the remaining 1
//  slice is carried over to the next day.
// Only 1
//  slice remains, so Alex eats it.
// In the second test case, Hao can eat 1
//  slice as follows:

// Split into m1=1
// , m2=1
// , and m3=2
// . Hao eats 1
//  slice, Alex eats 1
//  slice, and the remaining 2
//  slices are carried over to the next day.
// Only 2
//  slices remain, so Alex eats them all.

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << n / 3 << "\n";
    }
    return 0;
}



// 9.
//                                                     A. Notelock
// time limit per test1 second
// memory limit per test256 megabytes
// Teto is playing the hit rhythm game osu!. The game can be described by a binary string∗
//  s
//  of length n
//  and a positive integer k
//  where the following will happen in order:

// You will choose some positions in s
//  to protect.
// Then for each i
//  (1≤i≤n
// ) in increasing order, Teto can set si
//  to 0
//  if all the following are true:
// si=1
// ,
// si
//  is not protected,
// the previous k−1
//  elements do not contain 1
// . More formally, 1
//  does not occur in smax(1,i−k+1),…,si−1
// .
// You dislike Teto (for some reason). So determine the minimum number of positions you need to protect to force her to leave s
//  unchanged.

// ∗
// A binary string is a string that only consists of characters 0
//  and 1
// .

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤100
// ). The description of the test cases follows.

// The first line of each testcase contains integers n
//  and k
//  (2≤n≤1000
// ; 2≤k≤n
// ) — the length of s
//  and k
// .

// The second line of each test case contains a binary string s
//  of length n
//  consisting of characters 0
//  and 1
// .

// The sum of n
//  across all testcases does not exceed 1000
// .

// Output
// For each testcase, output the minimum number of positions you need to protect to force Teto to leave the string unchanged.

// Example
// Input
// 9
// 2 2
// 11
// 6 6
// 100001
// 5 3
// 10000
// 7 2
// 1010101
// 7 4
// 0000001
// 3 3
// 010
// 3 2
// 011
// 7 4
// 1001001
// 8 3
// 00000000
// Output
// 1
// 1
// 1
// 4
// 1
// 1
// 1
// 1
// 0
// Note
// For the first testcase, you can protect the first element and have: s=11
// . Now Teto cannot change s1
//  because it is protected and cannot change s2
//  because s1=1
// . It can be proven this is optimal.

// For the second testcase, you can protect only the first element and have s=100001
// . Teto cannot change s1
//  because it is protected and she cannot change s6
//  because there is 1
//  in the previous k−1
//  elements (100001
// ).

// For the fourth testcase, you must protect s1,s3,s5,s7
//  and have s=1010101
// . It can be shown that this is optimal. For example, if you did not protect s3
// , then Teto can change it to 0
//  (1010101
// )




#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int ans = 0;
        int last = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (last == -1 || i - last >= k)
                    ans++;
                last = i;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}


// 10.
//                                                 B. Bitwise Reversion
// time limit per test1.5 seconds
// memory limit per test256 megabytes

// You are given three non-negative integers x
// , y
//  and z
// . Determine whether there exist three non-negative integers a
// , b
//  and c
//  satisfying the following three conditions:

// a&b=x
// b&c=y
// a&c=z
// where &
//  denotes the bitwise AND operation.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first and only line of each test case contains three integers x
// , y
//  and z
//  (0≤x,y,z≤109
// ) — the target values of a&b
// , b&c
//  and a&c
// , respectively.

// Output
// For each test case, output "YES" if there exists three non-negative integers a
// , b
// , and c
//  satisfying the above conditions, and "NO" otherwise.

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// Input
// 5
// 1 1 1
// 3 2 6
// 4 8 12
// 9 10 12
// 12730 3088 28130
// Output
// YES
// YES
// NO
// YES
// NO
// Note
// In the first test case, a=3
// , b=5
// , and c=9
//  satisfies the condition as 3&5=1
// , 5&9=1
// , and 3&9=1
// .

// In the second test case, a=7
// , b=3
// , and c=22
//  satisfies the condition as 7&3=3
// , 3&22=2
// , and 7&22=6
// .

// In the third test case, it can be proven that there are no three non-negative integers a
// , b
// , and c
//  such that a&b=4
// , b&c=8
// , and a&c=12
// .

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        bool ok = true;

        for (int b = 0; b < 31; b++) {
            int xb = (x >> b) & 1;
            int yb = (y >> b) & 1;
            int zb = (z >> b) & 1;

            if (!(
                (xb == 0 && yb == 0 && zb == 0) ||
                (xb == 0 && yb == 1 && zb == 0) ||
                (xb == 0 && yb == 0 && zb == 1) ||
                (xb == 1 && yb == 0 && zb == 0) ||
                (xb == 1 && yb == 1 && zb == 1)
            )) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
//                                  A. Shift Sort
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a binary string∗
//  s
//  of length n
//  and you are allowed to perform the following operation any number of times (including zero):

// Choose 3
//  indices 1≤i<j<k≤n
//  and right shift or left shift the values on si
// , sj
// , sk
//  cyclically.
// For the binary string 110110, if we choose i=1
// , j=2
// , k=3
//  and perform a right shift cyclically, the string becomes 011110; if we choose i=4
// , j=5
// , k=6
//  and perform a left shift cyclically, the string becomes 110101.

// Determine the minimum number of operations required to sort the given binary string.

// ∗
// A binary string is a string that consists only of the characters 0 and 1.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤100
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (3≤n≤100
// ) — the length of the string.

// The second line contains a binary string s
//  of length n
// .

// Output
// For each test case, output a single integer — the minimum number of operations required to sort the given binary string.

// Example
// InputCopy
// 4
// 3
// 001
// 4
// 0110
// 6
// 110100
// 6
// 101011
// OutputCopy
// 0
// 1
// 2
// 1
// Note
// For the first test case, the given string is already sorted. So, no operations are needed.

// For the second test case, we can choose i=1
// , j=2
// , k=4
//  and perform a right shift cyclically. The string becomes equal to 0011, which is sorted.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ones = 0;
        for (char c : s) if (c == '1') ones++;

        int z = n - ones;              
        int ans = 0;
        for (int i = 0; i < z; i++) {  
            if (s[i] == '1') ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

//                                B. Villagers
// time limit per test1 second
// memory limit per test256 megabytes

// Steve lives in a village with n
//  other villagers. Unfortunately, due to disputes over the distribution of emeralds, none of those villagers are friends with any other villager. Furthermore, villager i
//  initially has a grumpiness of gi
// .

// Steve can perform the following operation any number of times:

// Select two villagers i
//  and j
//  and give them max(gi,gj)
//  emeralds to share. Both of their grumpinesses decrease by min(gi,gj)
// , and they become friends with each other if they weren't already.
// Steve wishes to make every villager friends with every other villager (possibly through some intermediate friendships); that is, from any villager, you can follow a path of friendships to reach any other villager. Since he does not want to inflate the village economy too much, calculate the minimum number of emeralds he must give away to accomplish this.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (2≤n≤2⋅105
// ) — the number of villagers.

// The second line of each test case contains n
//  integers g1,g2,…,gn
//  (1≤gi≤109
// ) — the initial grumpiness of each villager.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output a single integer — the minimum number of emeralds Steve must give away to make everyone friends.

// Example
// InputCopy
// 4
// 2
// 1 2
// 4
// 2 1 5 2
// 5
// 1000000000 1000000000 1000000000 1000000000 1000000000
// 6
// 3 1 4 1 5 9
// OutputCopy
// 2
// 7
// 3000000000
// 14
// Note
// In the first test case, the only valid operation is i=1
// , j=2
// . Steve gives them max(1,2)=2
//  emeralds, and they become friends.

// In the second test case, one optimal sequence of operations is as follows:

// Steve chooses i=1
// , j=3
// . He gives the villagers max(2,5)=5
//  emeralds, and their grumpiness decreases by min(2,5)=2
// . Now everyone's grumpiness is [0,1,3,2]
// ;
// Steve chooses i=2
// , j=4
// . He gives the villagers max(1,2)=2
//  emeralds, and their grumpiness decreases by min(1,2)=1
// . Now everyone's grumpiness is [0,0,3,1]
// ;
// Steve chooses i=1
// , j=2
// . He gives the villagers max(0,0)=0
//  emeralds, and their grumpiness decreases by min(0,0)=0
// . Now everyone's grumpiness is [0,0,3,1]
// .
// After this, the pairs of villagers (1,3)
// , (2,4)
//  and (1,2)
//  are directly friends, and every other pair of villagers is connected by a chain of mutual friendships. It can be shown that Steve cannot spend fewer than 7
//  emeralds to accomplish this.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        long long ans = 0;
        for (int i = 1; i < n; i += 2) ans += a[i];

        if (n % 2 == 1) ans += a[n - 1];

        cout << ans << "\n";
    }
    return 0;
}

//                               A. Homework
// time limit per test1 second
// memory limit per test256 megabytes
// Vlad and Dima have been assigned a task in school for their English class. They were given two strings a
//  and b
//  and asked to append all characters from b
//  to string a
//  in any order. The guys decided to divide the work between themselves and, after lengthy negotiations, determined who would add each character from string b
//  to a
// .

// Due to his peculiarities, Vlad can only add characters to the beginning of the word, while Dima can only add them to the end. They add characters in the order they appear in string b
// . Your task is to determine what string Vlad and Dima will end up with.

// Input
// Each test consists of several test cases. The first line contains a single integer t
//  (1≤t≤1000
// ) — the number of test cases. The description of the test cases follows.

// The first line contains an integer n
//  (1≤n≤10
// ) — the length of the string a
// .

// The second line contains the string a
// , consisting of lowercase letters of the English alphabet.

// The third line contains an integer m
//  (1≤m≤10
// ) — the length of the strings b
//  and c
// .

// The fourth line contains the string b
// , consisting of lowercase letters of the English alphabet.

// The fifth line contains the string c
// , consisting of the characters 'V' and 'D' — the distribution of the characters of string b
//  between Dima and Vlad. If ci
//  = 'V', then the i
// -th letter is added by Vlad; otherwise, it is added by Dima.

// Output
// For each test case, output the string that will result from Dima and Vlad's work.

// Example
// InputCopy
// 4
// 2
// ot
// 2
// ad
// DV
// 3
// efo
// 7
// rdcoecs
// DVDVDVD
// 3
// aca
// 4
// bbaa
// DVDV
// 3
// biz
// 4
// abon
// VVDD
// OutputCopy
// dota
// codeforces
// abacaba
// babizon
// Note
// In the first test case, there is initially a string ot
// . Then Dima appends the character a
//  to the end of the string, resulting in ota
// , and Vlad appends the last character, resulting in dota
// .

// In the second test case, the string will change as follows: efo→efor→defor→deforc→odeforc→odeforce→codeforce→codeforces

// In the third test case: aca→acab→bacab→bacaba→abacaba

// In the fourth test case: biz→abiz→babiz→babizo→babizon

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string a, b, c;
        cin >> n >> a;
        cin >> m >> b;
        cin >> c;

        deque<char> dq;
        for (char ch : a) dq.push_back(ch);

        for (int i = 0; i < m; i++) {
            if (c[i] == 'V') dq.push_front(b[i]);
            else dq.push_back(b[i]); // 'D'
        }

        for (char ch : dq) cout << ch;
        cout << "\n";
    }
    return 0;
}


//                              A. Letter Home
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an array of distinct integers x1,x2,…,xn
//  and an integer s
// .

// Initially, you are at position pos=s
//  on the X
//  axis. In one step, you can perform exactly one of the following two actions:

// Move from position pos
//  to position pos+1
// .
// Move from position pos
//  to position pos−1
// .
// A sequence of steps will be considered successful if, during the entire journey, you visit each position xi
//  on the X
//  axis at least once. Note that the initial position pos=s
//  is also considered visited.

// Your task is to determine the minimum number of steps in any successful sequence of steps.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t
//  (1≤t≤1000
// ) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains two integers n
//  and s
//  (1≤n≤10
// , 1≤s≤100
// ) — the number of positions to visit and the starting position.

// The second line of each test case contains n
//  integers x1,x2,…,xn
//  (1≤xi≤100
// ). It is guaranteed that for all 1≤i<n
// , it holds that xi<xi+1
// .

// Output
// For each test case, output the minimum number of steps in any successful sequence of steps.

// Example
// InputCopy
// 12
// 1 1
// 1
// 1 2
// 1
// 1 1
// 2
// 2 1
// 2 3
// 2 2
// 1 3
// 2 3
// 1 2
// 3 1
// 1 2 3
// 3 2
// 1 3 4
// 3 3
// 1 2 3
// 4 3
// 1 2 3 10
// 5 5
// 1 2 3 6 7
// 6 6
// 1 2 3 9 10 11
// OutputCopy
// 0
// 1
// 1
// 2
// 3
// 2
// 2
// 4
// 2
// 11
// 8
// 15
// Note
// In the first test case, no steps need to be taken, so the only visited position will be 1
// .

// In the second test case, the following path can be taken: 2→1
// . The number of steps is 1
// .

// In the third test case, the following path can be taken: 1→2
// . The number of steps is 1
// .

// In the fifth test case, the following path can be taken: 2→1→2→3
// . The number of steps is 3
// .

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];

        int L = x[0], R = x[n-1];
        int ans = (R - L) + min(abs(s - L), abs(s - R));
        cout << ans << "\n";
    }
    return 0;
}

//                                B. Shrink
// time limit per test2 seconds
// memory limit per test256 megabytes
// A shrink operation on an array a
//  of size m
//  is defined as follows:

// Choose an index i
//  (2≤i≤m−1
// ) such that ai>ai−1
//  and ai>ai+1
// .
// Remove ai
//  from the array.
// Define the score of a permutation∗
//  p
//  as the maximum number of times that you can perform the shrink operation on p
// .

// Yousef has given you a single integer n
// . Construct a permutation p
//  of length n
//  with the maximum possible score. If there are multiple answers, you can output any of them.

// ∗
// A permutation of length n
//  is an array consisting of n
//  distinct integers from 1
//  to n
//  in arbitrary order. For example, [2,3,1,5,4]
//  is a permutation, but [1,2,2]
//  is not a permutation (2
//  appears twice in the array), and [1,3,4]
//  is also not a permutation (n=3
//  but there is 4
//  in the array).

// Input
// The first line of the input contains an integer t
//  (1≤t≤103
// ) — the number of test cases.

// Each test case contains an integer n
//  (3≤n≤2⋅105
// ) — the size of the permutation.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output any permutation p1,p2,…,pn
//  that maximizes the number of shrink operations.

// Example
// InputCopy
// 2
// 3
// 6
// OutputCopy
// 1 3 2
// 2 3 6 4 5 1
// Note
// In the first test case:

// We choose p=[1,3,2]
// .
// Choose index 2
// , and remove p2
//  from the array. The array becomes p=[1,2]
// .
// It can be shown that the maximum number of operations we can perform is 1
// . Another valid answer is p=[2,3,1]
// .

// In the second test case:

// We choose p=[2,3,6,4,5,1]
// .
// Choose index 5
// , and remove p5
//  from the array. The array becomes p=[2,3,6,4,1]
// .
// Choose index 3
// , and remove p3
//  from the array. The array becomes p=[2,3,4,1]
// .
// Choose index 3
// , and remove p3
//  from the array. The array becomes p=[2,3,1]
// .
// Choose index 2
// , and remove p2
//  from the array. The array becomes p=[2,1]
// .
// The maximum number of operations we can perform is 4
// . Any permutation with a score of 4
//  is valid.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> ans;


        for (int i = 2; i <= n; i += 2) ans.push_back(i);


        int startOdd = (n % 2 == 1) ? n : n - 1;
        for (int i = startOdd; i >= 1; i -= 2) ans.push_back(i);

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}

//    False Alarm
// time limit per test1 second
// memory limit per test256 megabytes
// Yousef is at the entrance of a long hallway with n
//  doors in a row, numbered from 1
//  to n
// . He needs to pass through all the doors from 1
//  to n
//  in order of numbering and reach the exit (past door n
// ).

// Each door can be open or closed. If a door is open, Yousef passes through it in 1
//  second. If the door is closed, Yousef can't pass through it.

// However, Yousef has a special button which he can use at most once at any moment. This button makes all closed doors become open for x
//  seconds.

// Your task is to determine if Yousef can pass through all the doors if he can use the button at most once.

// Input
// The first line of the input contains an integer t
//  (1≤t≤1000
// ) — the number of test cases.

// The first line of each test case contains two integers n,x
//  (1≤n,x≤10
// ) — the number of doors and the number of seconds of the button, respectively.

// The second line of each test case contains n
//  integers a1,a2,...,an
//  (ai∈{0,1}
// ) — the state of each door. Open doors are represented by '0', while closed doors are represented by '1'.

// It is guaranteed that each test case contains at least one closed door.

// Output
// For each test case, output "YES" if Yousef can reach the exit, and "NO" otherwise.

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// InputCopy
// 7
// 4 2
// 0 1 1 0
// 6 3
// 1 0 1 1 0 0
// 8 8
// 1 1 1 0 0 1 1 1
// 1 2
// 1
// 5 1
// 1 0 1 0 1
// 7 4
// 0 0 0 1 1 0 1
// 10 3
// 0 1 0 0 1 0 0 1 0 0
// OutputCopy
// YES
// NO
// YES
// YES
// NO
// YES
// NO
// Note
// In the first test case, the optimal way is as follows:

// At time 0
// , the door is open, so Yousef passes.
// At time 1
// , the door is closed, Yousef can use the button now and pass through the door.
// At time 2
// , the button's effect is still on, so Yousef can still pass.
// At time 3
// , the button's effect has finished, but the door is open. Yousef passes and reaches the exit.
// In the second test case, Yousef has a 3-second button, but he would need at least a 4-second button to reach the exit. Therefore, the answer is NO.

// In the third test case, Yousef can turn on the button before starting to move. All the doors will stay open until he reaches the exit.


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int L = -1, R = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (L == -1) L = i;
                R = i;
            }
        }

        int need = R - L + 1;         
        cout << (need <= x ? "YES\n" : "NO\n");
    }
    return 0;
}


//  Race
// time limit per test2 seconds
// memory limit per test256 megabytes
// Alice and Bob participate in a game TV show. When the game starts, the prize will be dropped to a certain point, and whoever gets to it first will get the prize.

// Alice decided that she would start running from point a
// . Bob, however, has not yet chosen his starting position.

// Bob knows that the prize could drop either at point x
//  or at point y
// . He also knows that he can reach the prize faster than Alice if the distance from his starting position to the prize is strictly less than the distance from Alice's starting position to the prize. The distance between any two points c
//  and d
//  is calculated as |c−d|
// .

// Your task is to determine whether Bob can choose an integer point that is guarantee to get to the prize faster, regardless of where it appears (at point x
//  or y
// ). Bob can choose any integer point, except for a
//  (in particular, he can choose to start in point x
// , point y
// , or any other point, but not a
// ).

// Input
// The first line contains a single integer t
//  (1≤t≤1000
// ) — the number of test cases.

// The only line of each test case contains three integers a
// , x
// , y
//  (1≤a,x,y≤100
// ). Points a
// , x
// , and y
//  are pairwise distinct.

// Output
// For each test case, print "YES" (case insensitive) if Bob can choose an integer point that is guarantee to get to the prize faster, regardless of where it appears. Otherwise, print "NO" (case insensitive).

// Example
// InputCopy
// 3
// 1 3 4
// 5 3 1
// 3 1 5
// OutputCopy
// YES
// YES
// NO
// Note
// In the first example, Bob can choose point 4
// . If the prize will be at point x
// , then Bob's distance is |4−3|=1
//  and Alice's distance is |1−3|=2
// . If the prize will be at point y
// , then Bob's distance is |4−4|=0
//  and Alice's distance is |1−4|=3
// .

// In the second example, Bob can choose point 2
// . If the prize will be at point x
// , then Bob's distance is |2−3|=1
//  and Alice's distance is |5−3|=2
// . If the prize will be at point y
// , then Bob's distance is |2−1|=1
//  and Alice's distance is |5−1|=4
// .

// In the third example, Bob cannot choose a point to guarantee his victory.



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, x, y;
        cin >> a >> x >> y;

        int mn = min(x, y), mx = max(x, y);
        if (mn < a && a < mx) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}


// B. Cake Collection
// time limit per test1 second
// memory limit per test512 megabytes

// Maple wants to bake some cakes for Chocola and Vanilla.

// One day, she discovers n
//  magical cake ovens. The i
// -th oven bakes ai
//  cakes every second. The cakes remain in their respective ovens until they are collected.

// At the end of each second, she may teleport to any oven (including the one she is currently at) and collect all the cakes that have accumulated in that oven up to that point.

// Your task is to determine the maximum number of cakes Maple can collect in m
//  seconds.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤1000
// ). The description of the test cases follows.

// The first line of each test case contains two integers n
//  and m
//  (1≤n≤105
// , 1≤m≤108
// ) — the number of magical ovens and the number of seconds during which Maple will collect cakes.

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤105
// ) — the number of cakes the i
// -th oven bakes every second.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output a single integer representing the maximum number of cakes Maple can collect in m
//  seconds.

// Example
// InputCopy
// 3
// 3 4
// 1 2 3
// 3 2
// 1 2 3
// 1 1000
// 100000
// OutputCopy
// 20
// 8
// 100000000
// Note
// For the first test case, one optimal solution is as follows:

// At the end of the first second, the ovens contain 1
// , 2
// , and 3
//  cakes respectively. Maple teleports to oven 3
//  and collects all 3
//  cakes. Oven 3
//  now has 0
//  cakes remaining.
// At the end of the second second, the ovens contain 2
// , 4
// , and 3
//  cakes respectively. Maple teleports to oven 1
//  and collects all 2
//  cakes. Oven 1
//  now has 0
//  cakes remaining.
// At the end of the third second, the ovens contain 1
// , 6
// , and 6
//  cakes respectively. Maple teleports to oven 2
//  and collects all 6
//  cakes. Oven 2
//  now has 0
//  cakes remaining.
// At the end of the fourth second, the ovens contain 2
// , 2
// , and 9
//  cakes respectively. Maple teleports to oven 3
//  and collects all 9
//  cakes. Oven 3
//  now has 0
//  cakes remaining.
// In total, Maple collects 3+2+6+9=20
//  cakes.

// For the second test case, one optimal solution is as follows:

// At the end of the first second, the ovens contain 1
// , 2
// , and 3
//  cakes respectively. Maple teleports to oven 2
//  and collects all 2
//  cakes. Oven 2
//  now has 0
//  cakes remaining.
// At the end of the second second, the ovens contain 2
// , 2
// , and 6
//  cakes respectively. Maple teleports to oven 3
//  and collects all 6
//  cakes. Oven 3
//  now has 0
//  cakes remaining.
// In total, Maple collects 2+6=8
//  cakes.


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        long long k = min<long long>(n, m);
        long long startTime = m - k + 1; 
        long long ans = 0;

        for (long long j = 0; j < k; j++) {
            long long rate = a[n - k + j];      
            long long time = startTime + j;     
            ans += rate * time;
        }

        cout << ans << "\n";
    }
    return 0;
}


// A. Lever
// time limit per test2 seconds
// memory limit per test256 megabytes
// In Divergent Universe, The Lever iterates itself given two arrays a
//  and b
//  of length n
// . In each iteration, The Lever will do the following:

// Choose a random index i
//  such that ai>bi
// . Then, decrease ai
//  by 1
// . If there does not exist such i
// , ignore this step.
// Choose a random index i
//  such that ai<bi
// . Then, increase ai
//  by 1
// . If there does not exist such i
// , ignore this step.
// After each iteration, the Lever will check if step 1
//  is ignored, and if so, it will end its iteration.

// You're given the two arrays. Find the number of iterations that the Lever does. It can be shown this number is fixed over all possibilities of random indices that The Lever can choose for each step.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first line of each test case contains one integer n
//  (1≤n≤10
// ).

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤10
// ).

// The third line of each test case contains n
//  integers b1,b2,…,bn
//  (1≤bi≤10
// ).

// Output
// For each test case, output one integer — the number of iterations that the Lever does.

// Example
// InputCopy
// 4
// 2
// 7 3
// 5 6
// 3
// 3 1 4
// 3 1 4
// 1
// 10
// 1
// 6
// 1 1 4 5 1 4
// 1 9 1 9 8 1
// OutputCopy
// 3
// 1
// 10
// 7
// Note
// In the first sample case:

// In the first iteration, the Lever decreases a1
//  by 1
//  and increases a2
//  by 1
// , and a
//  becomes [6,4]
// .

// In the second iteration, the Lever decreases a1
//  by 1
//  and increases a2
//  by 1
// , and a
//  becomes [5,5]
// .

// In the third iteration, the Lever increases a2
//  by 1
// , and a
//  becomes [5,6]
// . Since it fails to decrease an element, its iteration ends. Therefore, the answer is 3
// .

// In the second sample case, the Lever does nothing in its first iteration, and thus it does only one iteration.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int iterations = 0;

        while (true) {
            iterations++;

            bool decreased = false;

د
            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) {
                    a[i]--;
                    decreased = true;
                    break;
                }
            }

            for (int i = 0; i < n; i++) {
                if (a[i] < b[i]) {
                    a[i]++;
                    break;
                }
            }

=
            if (!decreased) break;
        }

        cout << iterations << "\n";
    }
    return 0;
}







