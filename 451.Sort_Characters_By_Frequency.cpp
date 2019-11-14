class Solution {
public:
    string frequencySort(string s) {
        if( s=="" )return s;
        if (s.length() == 1 ) return s;
        int ascii[256]={0};
        string newString="";
        for(int i=0 ; i < s.length() ; i++ ) ascii[ s[i] ]++;
        bool found = true;
        while( found ){
            found=false;
            int max= 0, index= 0;
            for(int i= 0 ; i < 256 ; i++)
                if ( ascii[i] != 0 && ascii[i] > max){
                    found=true;
                    index =i;
                    max= ascii[i];
                }
            if(found)
                while( ascii[index] > 0){
                    newString+= char(index);
                    ascii[index]--;
                }
        }
        return newString;
    }
};
