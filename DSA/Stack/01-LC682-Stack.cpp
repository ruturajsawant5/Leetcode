class Solution {
public:
    int calPoints(vector<string>& operations) {
        int arr[1000];
        int top = 0;
        for(string op: operations) {
            if(op == "C") {
                top--;
           }
           else if(op == "D") {
            arr[top++] = 2 * arr[top-1];
           }
           else if(op == "+") {
            arr[top++] = arr[top-1] + arr[top-2];
           }
           else {
                arr[top++] = std::stoi(op);
           }
        }
        int res = 0;
        for(int i = 0; i < top; i++)
        res+=arr[i];

        return res;
    }
};