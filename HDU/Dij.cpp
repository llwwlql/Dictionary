void  ShorttestPath_DIJ(  MGraph  G,  int  v0,  PathMatrix  &P,  ShortPathTable  &D)
{
        for(  v  =  0;  v  <  G.vexnum;  ++v  )
       {
                final[v]  =  FALSE;
                D[v]  =  G.arcs[v0][v];
                for(  w  =  0;  w  <  G.vexnum;  ++w  )
                {
                        P[v][w]  =  FALSE;
                }
                if(  D[v]  <  INFINITY  )
                {  //如果有直接互通的两个顶点，直接将这个路径赋值到数组P[v]。
                        P[v][v0]  =  TRUE;
                        P[v][v]  =  TRUE;
                }
        }
        D[v0]  =  0;  final[v]  =  TRUE;

       /*下面开始主循环，每次求得v0到某个v顶点的最短路径，同时刷新之前的最短路径。*/
        for(  i  =  1;  i  <  G.vexnum;  ++i  )
        {  //  对于除了v0之外的顶点(这个循环仅仅限制次数，i的值不用).
                min  =  INFINITY;  //  假定初始的“最小值”为无穷大。
                for(  w  =  0;  w  <  G.vexnum;  ++w  )
                {
                        if(  !final[w]  )  //  w顶点在V - S中，即还未确定的顶点。
                                if(  D[w]  <  min  )
                                {
                                        v  =  w;
                                        min  =  D[w];  //  随着循环进行，依与v0的距离大小，从小到大取得顶点v，并标记进final。
                                }
                 }
                final[v]  =  TRUE;  //  标记已经找到
                for(  w  =  0;  w  <  G.vexnum;  w++  )
                {  //  更新路径
                        if(  !final[w]  &&  (min  +  G.arcs[v][w]  <  D[w]) )
                        {
                                D[w]  =  min  +  G.arcs[v][w];
                                P[w]  =  P[v];  //  把一行都给赋值了
                                P[w][w]  =  TRUE;
                         }
                }
        }
}
