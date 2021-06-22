/**
 * @author Ytalo Ramon
 * @date   18/06/2021
*/

#include "stdlib.h"
#include "stdio.h"
#include "../include/fenwick_tree_2d.h"


FenwickStructure *bitree_new(int **arr, int **bitree_arr, CoordCartesian shape){
    
    FenwickStructure *fkws = malloc(sizeof(FenwickStructure));
    if (!fkws)
        return NULL;

    fkws->shape.row = shape.row;
    fkws->shape.col = shape.col;

    fkws->arr = arr;
    fkws->bitree_arr = bitree_arr;

    return fkws;
}

void bitree_build(FenwickStructure *fwks){

    for (int i = 0; i < fwks->shape.row; ++i){
        for (int j = 0; j < fwks->shape.col; ++j){
            
            for (int k = i + 1; k <= fwks->shape.row; k += OPBITANDBITCOMP(k)){
                for (int t =  j + 1; t <= fwks->shape.col; t += OPBITANDBITCOMP(t)){
                    fwks->bitree_arr[k - 1][t - 1] += fwks->arr[i][j];
                }
            }

        }
    }
}

void bitree_update(FenwickStructure *fwks, int value, CoordCartesian coord){
    
    int dif = value - fwks->arr[coord.row][coord.col];
    fwks->arr[coord.row][coord.col] = value;

    for (int i = coord.row + 1; i <= fwks->shape.row; i += OPBITANDBITCOMP(i)){
        for (int j = coord.col + 1; j <= fwks->shape.col; j += OPBITANDBITCOMP(j)){
            fwks->bitree_arr[i - 1][j - 1] += dif;
        }
    }
}

int bitree_sum(FenwickStructure *fwks, CoordCartesian e_coord){

    int sumt = 0;

    for (int i = e_coord.row; i > 0; i -= OPBITANDBITCOMP(i)){
        for (int j = e_coord.col; j > 0; j -= OPBITANDBITCOMP(j)){
            sumt += fwks->bitree_arr[i - 1][j - 1];
        }
    }

    return sumt;
}

int bitree_sum_between(FenwickStructure *fwks, CoordCartesian s_coord, CoordCartesian e_coord){
   
    return bitree_sum(fwks, e_coord) 
            - bitree_sum(fwks, (CoordCartesian){s_coord.row, e_coord.col})
            - bitree_sum(fwks, (CoordCartesian){e_coord.row, s_coord.col})
            + bitree_sum(fwks, (CoordCartesian){s_coord.row, s_coord.col});
}
