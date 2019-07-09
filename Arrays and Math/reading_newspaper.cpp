/*
You have a newspaper which has N lines to read. You decided to start reading the 1st line from Monday. You are given a schedule which states how many lines you can read from the newspaper in a day.  You are very strict in reading the newspaper and you will read as much as you can every day, determine, which day of the week you will read the last line of the newspaper. Input
The first argument contains the single integer N (1 ≤  N ≤ 1000) — the number of lines in the newspaper.

The second argument is an array of size 7 and it contains seven non-negative space-separated integers that do not exceed  1000 — those integers represent how many lines you can read on Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday correspondingly.

Note: It is guaranteed that at least one of those numbers is larger than zero.
Output
Return a single number — the number of the day of the week, when you will finish reading the newspaper. The days of the week are numbered starting with one in the order: Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday.
Examples Input
100  
15 20 20 15 10 30 45
Output
6

*/
int Solution::solve(int A, vector<int> &B) {
    while(A>0)
    {
        for(int i=0;i<B.size();i++)
        {
            A=A-B[i];
            if(A<=0)
            {
                return i+1;
            }
        }
    }
}
