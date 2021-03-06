#include <stdio.h>
#include "ip_lib.h"
#include "bmp.c"

int main()
{

    /*test free*/

    Bitmap *b = NULL;

    ip_mat *input_img = NULL;

    b = bm_load("fullmoon.bmp");

    Bitmap *c = NULL;

    ip_mat *input_img2 = NULL;

    c = bm_load("mongolfiere.bmp");

    input_img = bitmap_to_ip_mat(b);
    input_img2 = bitmap_to_ip_mat(c);

    /*     ip_mat *blend = ip_mat_blend(input_img, input_img2, 0);
    Bitmap *bmblend = ip_mat_to_bitmap(blend);
    bm_save(bmblend, "blended.bmp"); */

    ip_mat *corrupt = ip_mat_brighten(input_img, 50);
    clamp(corrupt, 0, 255);
    Bitmap *bmcorrupt = ip_mat_to_bitmap(corrupt);
    bm_save(bmcorrupt, "corrupt.bmp");

    ip_mat *gray = ip_mat_to_gray_scale(input_img);
    Bitmap *bmgray = ip_mat_to_bitmap(gray);
    bm_save(bmgray, "togray.bmp");

    ip_mat *convolata = ip_mat_create(5, 5, 3, 22);
    ip_mat *filtro = ip_mat_create(3, 3, 3, 0.5);

    ip_mat *edge_filter = create_edge_filter();
    ip_mat *emboss_filter = create_emboss_filter();
    ip_mat *sharpen_filter = create_sharpen_filter();
    ip_mat *anozze = ip_mat_convolve(convolata, filtro);
    ip_mat *paddata = ip_mat_padding(convolata, 1, 1);
    ip_mat *subset = ip_mat_subset(paddata, 4, 7, 4, 7);
    ip_mat *cane = create_average_filter(3, 3, 3);

    ip_mat *gaussian_filter = create_gaussian_filter(9, 9, 3, 5);
    /*     ip_mat_show(gaussian_filter); */

    ip_mat *gaussian_filtered = ip_mat_convolve(input_img2, gaussian_filter);
    clamp(gaussian_filtered, 0, 255);
    Bitmap *pippo = ip_mat_to_bitmap(gaussian_filtered);
    bm_save(pippo, "gaussian_filter.bmp");

    ip_mat_free(gray);
    ip_mat_free(corrupt);
    /*    ip_mat_free(blend); */
    bm_free(bmgray);
    bm_free(bmcorrupt);
    /* bm_free(bmblend); */

    ip_mat_free(filtro);
    ip_mat_free(emboss_filter);
    ip_mat_free(edge_filter);
    ip_mat_free(sharpen_filter);

    ip_mat_free(convolata);
    ip_mat_free(anozze);
    ip_mat_free(paddata);
    ip_mat_free(subset);
    ip_mat_free(cane);

    ip_mat_free(input_img);
    bm_free(b);
    ip_mat_free(input_img2);
    bm_free(c);

    /*

    ip_mat *padding = ip_mat_create(2, 3, 3, 22);
    printf("---prima---\n");
    ip_mat_show(padding);
    ip_mat *result = ip_mat_padding(padding, 1, 1);
    printf("---dopo---\n");
    ip_mat_show(result);

    ip_mat_free(padding);
    ip_mat_free(result);
    

    bm_free(b);
    bm_free(c); 
    bm_free(bmblend); 
    bm_free(bmgray); 
    bm_free(bmcorrupt);
    ip_mat_free(corrupt);
    ip_mat_free(input_img);
    ip_mat_free(input_img2);
    


    ip_mat_free(convolata);
    ip_mat_free(filtro);
    ip_mat_free(anozze);
    ip_mat_free(blend); 
    ip_mat_free(gray); 

    printf("sottomatrice---------------------------------\n");

    sub_mat = ip_mat_subset(nuova,1, 6, 1, 1);
    ip_mat_show(sub_mat);

    printf("SECONDA MAT-------------------------------\n");
    ip_mat *secondamat = ip_mat_create(3, 2, 5, 59.9);
    ip_mat_show(secondamat);

    printf("concatenata---------------------------------\n");

    concatenata = ip_mat_concat(nuova, secondamat, 2);
    ip_mat_show(concatenata);

      
    printf("stat--------------------------------\n");
     compute_stats(nuova);
    ip_mat_show_stats(nuova); 

    printf("SOMMA--------------------------------\n");

    sum=ip_mat_sum(nuova,secondamat);
    ip_mat_show(sum);
 
    printf("STATISTICHE DI SUM------------------------\n");

    compute_stats(sum);
    ip_mat_show_stats(sum);

    printf("sottrazione--------------------------------\n");

    sub=ip_mat_sub(nuova,secondamat);
    ip_mat_show(sub);

    printf("STATISTICHE DI SUM------------------------\n");

    compute_stats(sub);
    ip_mat_show_stats(sub); 

    corrupt test 

    Bitmap *c = NULL;
    Bitmap *b = NULL;

    ip_mat *input_img = NULL;
    ip_mat *input_img2 = NULL;

    b = bm_load("flower.bmp");
    c = bm_load("mongolfiere.bmp");
    input_img = bitmap_to_ip_mat(b);
    input_img2 = bitmap_to_ip_mat(c);

    ip_mat *corrupt = ip_mat_corrupt(input_img, 50);
    Bitmap *bmcorrupt = ip_mat_to_bitmap(corrupt);
    bm_save(bmcorrupt, "corrupt.bmp");

    ip_mat *convolata = ip_mat_create(5, 5, 3, 22);
    printf("-----------CONVOLATA---------------\n");
    ip_mat_show(convolata);

    ip_mat *filtro = ip_mat_create(3, 3, 3, 0.5);
    printf("-----------filtro---------------\n");
    ip_mat_show(filtro);

    ip_mat *anozze = ip_mat_convolve(convolata, filtro);
    printf("-----------ANOZZE---------------\n");
    ip_mat_show(anozze);

    ip_mat *paddata = ip_mat_padding(convolata, 1, 1);
    ip_mat_show(paddata);

    ip_mat *subset = ip_mat_subset(paddata, 4, 7, 4, 7);
    ip_mat_show(subset);

    ip_mat *cane = create_average_filter(3, 3, 3);
    ip_mat_show(cane);

    ip_mat *edge_filter = create_edge_filter();
    ip_mat *emboss_filter = create_emboss_filter();
    ip_mat *sharpen_filter = create_sharpen_filter();

    ip_mat *risultato = ip_mat_convolve(input_img, cane);
    clamp(risultato, 0, 255);
    Bitmap *average = ip_mat_to_bitmap(risultato);
    bm_save(average, "average_filter.bmp");

    bm_free(b);
    bm_free(c);
    bm_free(bmcorrupt);
    ip_mat_free(input_img);
    ip_mat_free(input_img2);
    ip_mat_free(corrupt);

    */

    return 0;
}
