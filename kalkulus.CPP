#include <conio.h>
#include <stdio.h>
#include <math.h>
#define PHI 3.141592654

int main()
{
    // deklarasi variabel
    int i,j, loop;
    float init, x, eps, x1, fxi;

    printf("Mencari Solusi Persamaan f(x)  = 8x^4 + 11x^3 + 7x + 3 - cos(x)\n");
    printf("Dari persamaan f(x), maka diperoleh f(x)' = 32x^3 + 33x^2 + 7 + sin(x)\n");
    printf("====================================================\n");

    // meminta input untuk memasukkan nilai awal/nilai tebakan
    printf("Masukkan bilangan inisiasi : ");
    scanf("%f", &init);
    x = init;
    // meminta input untuk memasukkan banyak pengulangan
    printf("Masukkan banyak pengulangan : ");
    scanf("%d", &loop);

    printf ("============================================================\n");
    printf ("iterasi ke-i | nilai xi      | fxi        | error semu ((xi-xi+1)/xi+1)\n");
    printf ("============================================================\n");
 
    // looping untuk menghitung nilai x sesuai dengan nilai tebakan awal dan banyak pengulangan yang diberikan
    for(i = 0; i < loop ; i++)
    {
        x = x - ((8*x*x*x*x + 11*x*x*x + 7*x + 3 - cos(x * PHI / 180)) / (32*x*x*x + 33*x*x + 7 + sin(x * PHI / 180)));
        fxi = 32*x*x*x + 33*x*x - 7 + sin(x * PHI / 180);

     // looping untuk menghitung nilai x selanjutnya, untuk membantu mencari nilai error semu
        for(j=i+1; j<loop+1;j++)
        {
          x1 = x - ((8*x*x*x*x + 11*x*x*x + 7*x + 3 - cos(x * PHI / 180)) / (32*x*x*x + 33*x*x + 7 + sin(x * PHI / 180)));
 
        }

        // untuk menghitung error semu
        eps=fabs((x1-x)/x);
 
        // menampilkan hasil perhitungan
        printf("%d            | %f       | %f   | %f\n", i, x,fxi, eps);
    }

    printf("==============================================================\n");
    printf("Solusi persamaan 8x^4 + 11x^3 + 7x + 3  = cos(x) adalah x = %f\n", x);
     getch();
 
}