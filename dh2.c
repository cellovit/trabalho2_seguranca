// criar uma função uint64_t powmod(uint64_t g, uint64_t c, uint64_t p) que retorna o valor de g^c mod p

#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <math.h>

uint64_t powmod(uint64_t g, uint64_t c, uint64_t p) {

	uint64_t test;	
	uint64_t n = g;
	
	for(test = 1; c; c >>= 1)
    {
        if (c & 1)
            test = ((test % p) * (n % p)) % p;
        n = ((n % p) * (n % p)) % p;
    }

    return test;

//    for (i = 0; i < c; i++){
//    	
//    	
//    	
//    	g *= c;
//	}
//        
//	return g % p;
}

int main() {
	
	uint64_t p, g, c;
	
	printf("Insira o valor de p : ");
 	scanf("%"SCNu64, &p);
 	printf("\n");
 	//printf("%"SCNu64, p);
 
 	printf("Insira o valor de g : ");
 	scanf("%"SCNu64, &g);
 	printf("\n");
 	//printf("%"SCNu64, g);
 
 	uint64_t a, b, Alice, Bob = 0;
 	
 	a = 1804289383;
	printf("Valor aleatorio para Alice : ");	
	printf("a = %" PRIx64 "\n", a);
	
	Alice = powmod(g, a, p);
	
	printf("Alice : ");	
	printf("%" PRIx64 "\n", Alice);
	
	b = 846930886;
	printf("Valor aleatorio para Bob : ");	
	printf("b = %" PRIx64 "\n", b);
	
	Bob = powmod(g, b, p);
	
	printf("Bob : ");	
	printf("%" PRIx64 "\n", Bob);
	
	uint64_t segredoAlice, segredoBob;
	
	segredoAlice = powmod(Bob, a, p);
	
	printf("Segredo Alice : ");	
	printf("%" PRIx64 "\n", segredoAlice);
	
	segredoBob = powmod(Alice, b, p);
	
	printf("Segredo Bob : ");	
	printf("%" PRIx64 "\n", segredoBob);

	return 0;
}


