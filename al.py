
from sklearn.metrics.pairwise import euclidean_distances
import numpy as np 

class Cluster:
    
    def __init__(self, n):
        ''' '''
        self.n = n
        self.nodes = set([n])
        self.active = True
        self.join_n = a = -1 

    def merge(self, c):
        ''' '''
        self.nodes = self.nodes.union(c.nodes)
        c.active = False
        c.join_n = self.n
        
    def get_n(self):
        if self.join_n == -1:
            return self.n
        return self.join_n
        
class HierarchicalClustering:
    
    def __init__(self, alpha = 1.01, max_iteration = 200, debug= False, delta=0., stop_neg_sum = True, betta = 2., n_clusters=10):
        ''' '''
        self.alpha = alpha
        self.betta = betta
        self.max_iteration = max_iteration
        self.debug = debug
        self._c_all = []
        self.delta = delta
        self.stop_neg_sum = stop_neg_sum
        self.n_clusters= n_clusters
        self.labels_ = []
    
    def score(sefl, x):
        ''' '''
    
    def _get_min(self, M, C):
        r = []
        for i in range(len(C)):  
            for j in range(i,len(C)):
                if( M[i][j] <= 0):
                    continue
                a = C[i].get_n()
                b = C[j].get_n()  
                if(a == b):
                    continue
                r.append( M[i][j])    
        return min(r)    
            
    
    def fit(self, x):
        ''' '''
        self._c_all = []
        y_ = []
        M =  euclidean_distances(x,x)
        C = []
        size = len(M)
        for i in range(size): 
            C.append( Cluster(i) )
        
        delta = self.delta
        
        for i in range(self.max_iteration): 
            d = np.min(M[M > 0]) * self.alpha 
            #d = self._get_min(M, C) * self.alpha
            if d > delta:
                delta = d  
            if(self.debug):   
                print('delta: %.3f, d: %.3f' % (delta, d))    
            M_ = M - delta
            ''' join clusters '''
            join = False
            for i in range(size):  
                for j in range(i,size):  
                    if(M[i][j] <= 0 or M_[i][j] > 0): # old
                        continue
                    if i == j:
                        continue 
                    a = C[i].get_n()
                    b = C[j].get_n() 
                    if(a == b):
                        continue  
                    #if  (C[b].active == False or C[a].active == False):
                    #    continue
            
                    C[a].merge(C[b])
                    for s in C[b].nodes:
                        C[s].join_n = a
                    #sb = C[b][0]
                    #C[a][0] = C[a][0].union(sb)  
                    #for s in sb:
                    #    C[s][1] = C[s][1] - 1
                    #    C[s][2] = a 
                    #C[a][1] = 1 
                    #M_[b,:] = 0 
                    #M_[:,b] = 0

                    #print(M_[b])
                    join = True
            #print('join', join)        
            if join == False:
                #break
                delta = delta * self.betta
                continue
            ''' update matrix '''
            #delta = d
            M =   M_ 
                    
            if len(M[M > 0]) == 0:
                print('len(M[M > 0]) == 0')
                #print(M_)
                break
              
            #print(C)
            y_ = np.zeros(size)
            cl = 0
            for c in C:
                if(c.active == True): 
                    for i in c.nodes:
                        y_[i] = cl
                    cl = cl + 1
                    
            self._c_all.append(y_)  
            print('unique len: %d' % len(np.unique(y_)))
            if len(np.unique(y_)) <= self.n_clusters:
                print('len(np.unique(y_)) == 1')
                break
            neg,pos = [],[]    
            for i in range(size): 
                for j in range(i,size):
                    if(M[i][j] <= 0):
                        neg.append(delta + np.abs(M[i][j]))
                    else:
                        pos.append(M[i][j])    
            if(self.debug):
                print('Sum pos: %.3f, sum neg: %.3f, Std pos: %.3f, Std neg: %.3f' % 
                      (sum(pos), sum(neg),np.std(pos), np.std(neg))) 
            if self.stop_neg_sum and sum(pos) < sum(neg): 
                print('sum(pos) < sum(neg)')
                #break 
                
        self.labels_  = y_      
        return y_                
        
    def print_name(self):
        print('Hierarchical clustering')
        
