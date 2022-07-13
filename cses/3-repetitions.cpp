#include <iostream>
#include <string>

int main() {
        std::string dna;
        std::cin >> dna;
#ifdef DEBUG
        std::cout << dna << '\t' << dna.length() << '\n';
#endif
        int a = 0,
            c = 0,
            g = 0,
            t = 0;
        int Ma = 0,
            Mc = 0,
            Mg = 0,
            Mt = 0;

        char last = '\0';  // initialize to null to prevent accidental intersects
        for (int i = 0; i < dna.length(); i++) {
                switch (dna[i]) {
                        case 'A':
                                if (last != 'A') {
                                        if (a > Ma)
                                                Ma = a;
                                        a = 0;
                                }
                                a += 1;
                                last = 'A';
                                break;
                        case 'C':
                                if (last != 'C') {
                                        if (c > Mc)
                                                Mc = c;
                                        c = 0;
                                }
                                c += 1;
                                last = 'C';
                                break;
                        case 'G':
                                if (last != 'G') {
                                        if (g > Mg)
                                                Mg = g;
                                        g = 0;
                                }
                                g += 1;
                                last = 'G';
                                break;
                        case 'T':
                                if (last != 'T') {
                                        if (t > Mt)
                                                Mt = t;
                                        t = 0;
                                }
                                t += 1;
                                last = 'T';
                                break;
                }

        }
        if (!Ma)
                Ma = a;
        if (!Mc)
                Mc = c;
        if (!Mg)
                Mg = g;
        if (!Mt)
                Mt = t;


        //  tfw (the face when) you completely forget the problem at hand
        int greater, greater1, final;
#ifdef DEBUG
        std::cout << "a: " << a << '\t' << "t: " << t << '\t' << "g: " << g << '\t' << "c: " << c << '\n';
        std::cout << "a: " << Ma << '\t' << "t: " << Mt << '\t' << "g: " << Mg << '\t' << "c: " << Mc << '\n';
#endif
        greater = (Ma > Mc) ? Ma : Mc;
        greater1 = (Mg > Mt) ? Mg : Mt;
        final = (greater > greater1) ? greater : greater1;
         //

        std::cout << final;


        return 0;
}