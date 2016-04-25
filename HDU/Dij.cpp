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
                {  //�����ֱ�ӻ�ͨ���������㣬ֱ�ӽ����·����ֵ������P[v]��
                        P[v][v0]  =  TRUE;
                        P[v][v]  =  TRUE;
                }
        }
        D[v0]  =  0;  final[v]  =  TRUE;

       /*���濪ʼ��ѭ����ÿ�����v0��ĳ��v��������·����ͬʱˢ��֮ǰ�����·����*/
        for(  i  =  1;  i  <  G.vexnum;  ++i  )
        {  //  ���ڳ���v0֮��Ķ���(���ѭ���������ƴ�����i��ֵ����).
                min  =  INFINITY;  //  �ٶ���ʼ�ġ���Сֵ��Ϊ�����
                for(  w  =  0;  w  <  G.vexnum;  ++w  )
                {
                        if(  !final[w]  )  //  w������V - S�У�����δȷ���Ķ��㡣
                                if(  D[w]  <  min  )
                                {
                                        v  =  w;
                                        min  =  D[w];  //  ����ѭ�����У�����v0�ľ����С����С����ȡ�ö���v������ǽ�final��
                                }
                 }
                final[v]  =  TRUE;  //  ����Ѿ��ҵ�
                for(  w  =  0;  w  <  G.vexnum;  w++  )
                {  //  ����·��
                        if(  !final[w]  &&  (min  +  G.arcs[v][w]  <  D[w]) )
                        {
                                D[w]  =  min  +  G.arcs[v][w];
                                P[w]  =  P[v];  //  ��һ�ж�����ֵ��
                                P[w][w]  =  TRUE;
                         }
                }
        }
}
