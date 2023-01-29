import java.math.BigInteger;
public class Main {
    public static void main(String [] args){
        //decimal representation
        BigInteger b1 = new BigInteger("1222222222");   //contain decimal representation of the given decimal  base string
        System.out.println(b1);
        //different base system repsentation
        BigInteger b2 = new BigInteger("101",2);     //101 is in base 2
        System.out.println(b2);
        System.out.println(b2.toString(2)); // output in base 2
        BigInteger b3 = new BigInteger("101",3);    //101 is in base 3
        System.out.println(b3); // if explicitly is not triggered then it will give decimal value
//        /*
//
//        */
//        //arithmetic operations
        BigInteger b4 = new BigInteger("122222222222222222222222");
        BigInteger b5 = new BigInteger("2334893937104101401817");
        System.out.println(b4.add(b5));     //returns a BigIntegar by adding b4 and b5
        System.out.println(b4.subtract(b5));//returns a Bigintegar by subtracting b5 from b4(this - rhs )
        System.out.println(b4.multiply(b5));//returns a BigIntegar by multiplying b4 and b5
        System.out.println(b4.divide(b5));  // b5 divides b4 (this / rhs )
        System.out.println(b4.remainder(b5));// this % rhs here (b4 % b5)
        System.out.println(b4.mod(b5));       //this % rhs
        //mod and remainder function is almost same, only difference is that mod function always
         //returns a positive BigIntegar
//        /*
//
//        */
 //       some function for math
        BigInteger b6 = new BigInteger("11111");
        BigInteger b7 = new BigInteger("322222222222211111");
        int b8 = 12345;
        BigInteger b9 = new BigInteger("12345");
        //exponent function: remember here p ^ x where x is an integar ,Not a BigIntegar
        System.out.println(b6.pow(b8)); // b6 ^ b8
        //gcd(x,y) if this == 0 and rhs == 0 then return 0
        System.out.println(b6.gcd(b7)); //gcd(b6,b7)
        //this.modPow(x,y) = this^x mod y here y is a BigIntegar
        System.out.println(b6.modPow(b9,b7));   //(b6 ^ b9) mod b7
        //modular multiplicative inverse
        System.out.println(b6.modInverse(b9));  //(b6)^-1 mod b9 whree b9 is not prime

/*


 */
//        bitwise operation
        BigInteger c1 = new BigInteger("1100110");
        BigInteger c2 = new BigInteger("111111");
        int n = 5;
        System.out.println(c1);
        System.out.println(c1.shiftLeft(n));    // this << n
        System.out.println(c1.shiftRight(n));   //this >> n
        System.out.println(c1.and(c2)); //AND(c1,c2)
        System.out.println(c1.or(c2));  //OR(c1,c2)
        System.out.println(c1.not());   //NOT(c1)
        System.out.println(c1.xor(c2)); //xor(c1,c2)
        System.out.println(c1.testBit(n));  //returns true if nth bit is set otherwise returns false
        System.out.println(c1.setBit(n));   //returns a BigIntegar after setting nth bit
        System.out.println(c1.clearBit(n)); //clear ith bit from c1
        System.out.println(c1.flipBit(n));  // flip nth bit from c1
        System.out.println(c1.getLowestSetBit());   // index of the righmost bits that are set

        // hash code
        System.out.println(c1.hashCode());

        //toString method for output
        BigInteger d1 = new BigInteger("122222222");
        System.out.println(d1.toString());  //returns decimal
        System.out.println(d1.toString(2)); //gives value of d1 in base 2







    }
}
