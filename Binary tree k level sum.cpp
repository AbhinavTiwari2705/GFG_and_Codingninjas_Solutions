int kLevelSum(int K, string S) {
       // code here
       
       int level = -1 ;
       int sum = 0 ;
       for( int i = 0 ; i< S.size() ; i++)
       {
           if(S[i]=='(')
           {
               level++ ;
           }
           else if(S[i] == ')')
           {
               level-- ;
           }
           else 
           {
          
            if(level==K){
                string st = "";
                st=st+S[i];
                while(S[i+1] != '('){
                    i++;
                    st=st+S[i];
                }
                sum=sum + stoi(st);
            }
           }
       }
       
       return sum ;
   }
