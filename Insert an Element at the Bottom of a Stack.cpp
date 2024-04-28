class Solution{
private:
    void helper(stack<int>& st,int n){
        if(st.size()==0){
            st.push(n);
            return;
        }
        int a=st.top();
        st.pop();
        helper(st,n);
        st.push(a);
        
    }
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        helper(st,x);
        return st;
    }
};
