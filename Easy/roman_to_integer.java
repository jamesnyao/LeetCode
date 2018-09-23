class Solution {
    public int romanToInt(String s) {
        /*
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000
        */
        int ret = 0;
        char c = ' ';
        for (int i = 0; i < s.length(); i++) {
            c = s.charAt(i);
            if (c == 'M') {
                ret += 1000;
            } else if (c == 'D') {
                ret += 500;
            } else if (c == 'C') {
                try {
                    c = s.charAt(i+1);
                    if (c == 'D') {
                        ret += 400;
                        i++;
                    } else if (c == 'M') {
                        ret += 900;
                        i++;
                    } else {
                        ret += 100;
                    }
                } catch (IndexOutOfBoundsException e) {
                    ret += 100;
                } finally {}
            } else if (c == 'L') {
                ret += 50;
            } else if (c == 'X') {
                try {
                    c = s.charAt(i+1);
                    if (c == 'L') {
                        ret += 40;
                        i++;
                    } else if (c == 'C') {
                        ret += 90;
                        i++;
                    } else {
                        ret += 10;
                    }
                } catch (IndexOutOfBoundsException e) {
                    ret += 10;
                } finally {}
            } else if (c == 'V') {
                ret += 5;
            } else if (c == 'I') {
                try {
                    c = s.charAt(i+1);
                    if (c == 'V') {
                        ret += 4;
                        i++;
                    } else if (c == 'X') {
                        ret += 9;
                        i++;
                    } else {
                        ret++;
                    }
                } catch (IndexOutOfBoundsException e) {
                    ret++;
                } finally {}
            } else {
                System.err.println("Invalid symbol");
                System.exit(1);
            }
        }
        return ret;
    }
}
