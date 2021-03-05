class Solution {
public:
    string intToRoman(int num) {
        
        return intToRomanOneBit(num/1000, 'M', 0, 0)              // 千位
             + intToRomanOneBit((num%1000)/100, 'C', 'D', 'M')    // 百位
             + intToRomanOneBit((num%100)/10, 'X', 'L', 'C')      // 十位
             + intToRomanOneBit(num%10, 'I', 'V', 'X');           // 个位
    }
private:
    string intToRomanOneBit(int num, char one, char five, char ten){
        if(num <=3 )
            return string(num, one);
        if(num == 4)
            return string("") + one + five;
        if(num <= 8)
            return string("") + five + string(num-5, one);
        return string("") + one + ten;
    }
};
