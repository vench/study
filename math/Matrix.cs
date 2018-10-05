namespace myApp.Math {

    using System;
    class Matrix {
        private double[] data;
        private int nRows;
        private int nCols;



        public Matrix(int nRows, int nCols) {
            if(nRows + nCols == 0) {
                throw new System.Exception("initData is empty");
            } 
            this.nRows = nRows;    
            this.nCols = nCols;
            this.data = new double[nRows * nCols]; 
        }

        public Matrix(double[,] initData) : 
            this(initData.GetLength(0), initData.GetLength(1)) {     

            for(int i = 0; i < nRows; i ++) {
                for(int j = 0; j < nCols; j ++) {
                    this.data[i*nCols+j] = initData[i,j];
                }
            }
        }


        //FIELDS
        public double this[int i, int j]{  
            get {
                return this.data[i * nCols + j];
            }  
            set {
                this.data[i * nCols + j] = value;     
            }
        }

        public int Rows {
             get { return nRows; }
         }
        public int Columns { 
            get { return nCols; }
        }

        public int? Size { 
            get {
                if(nRows != nCols) {
                    return null;
                }
                return nRows;
            }
         }
 
        // Является ли матрица квадратной
        public bool IsSquared { 
            get{ return nCols == nRows; }
        }

        // Является ли матрица нулевой
        public bool IsEmpty{ 
            get {return !(SumMatrix() > 0);}
        }
        
        //Является ли матрица единичной
        public bool IsUnity { 
            get{ 
                if(!IsDiagonal) {
                    return false;
                }

                return SumMatrix() == nRows; 
            }
        }    
        //Является ли матрица диагональной
        public bool IsDiagonal { 
            get{ 
                if(!IsSquared) {
                    return false;
                }
                for(int i = 0; i < nRows; i ++) {
                    for(int j = 0; j < nCols; j ++) {
                        if(i != j && this[i, j] != 0) {
                            return false;
                        }
                    }
                }
                return true;
            } 
        }
        //Является ли матрицa симметричной
        public bool IsSymmetric { 
            get{ 
                if(!IsSquared) {
                    return false;
                }
                for(int i = 0; i < nRows; i ++) {
                    for(int j = 0; j < nCols; j ++) { 
                        if(i != j && this[i, j] != this[j,i]) {
                            return false;    
                        }
                    }
                }
                return true;
            } 
        }

        // OPERATORS

        public static Matrix operator+(Matrix m1,Matrix m2) {
            if(m1.nCols != m2.nCols || m1.nRows != m2.nRows) {
                throw new Exception("Matrix of different sizes");
            }
            Matrix m = m1.Clone();
            for(int i = 0; i < m.data.Length; i ++) {
                   m.data[i] += m2.data[i]; 
            }
            return m;
        }

        public static Matrix operator-(Matrix m1, Matrix m2) {
            if(m1.nCols != m2.nCols || m1.nRows != m2.nRows) {
                throw new Exception("Matrix of different sizes");
            }
            Matrix m = m1.Clone();
            for(int i = 0; i < m.data.Length; i ++) {
                   m.data[i] -= m2.data[i]; 
            }
            return m;
        }

        public static Matrix operator*(Matrix m1, double d) {
            Matrix m = m1.Clone();
            for(int i = 0; i < m.data.Length; i ++) {
                   m.data[i] *= d; 
            }
            return m;
        }

        public static Matrix operator*(Matrix m1, Matrix m2) {
            if(m1.nCols != m2.nRows) {
                throw new Exception("Error matrix dimension");
            }
            Matrix m = new Matrix(m1.nRows, m2.nCols);
            for(int i = 0; i < m1.Rows; i ++) {
                for(int j = 0; j < m2.nCols; j ++) {                    
                    for(int n = 0; n < m1.nCols; n ++) {
                       m[i,j] += m1[i,n] * m2[n,j];
                    }                    
                }
            }
            return m;
        }
 
        public static explicit operator Matrix(double[,] arr) {
            return new Matrix(arr);
        }


        // METHODS

        public double SumMatrix() {
            double d = 0.0;
            for (int i = 0; i < data.Length; i ++) {
                d += data[i];
            }
            return d;        
        }

        public Matrix Transpose() {
            Matrix m = new Matrix(nCols, nRows);
            for(int i = 0; i < nRows; i ++) {
                for(int j = 0; j < nCols; j ++) {
                    m[j,i] = this[i,j];
                }
            }
            return m;
         }

        // вычисления следа матрицы
        public double Trace() {
            double d = 0.0;
            for(int i = 0; i < Size; i ++) {
                d += this[i,i];
            }
            return d;
        }

        public Matrix Clone() {
            Matrix m = new Matrix(nRows, nCols);
            data.CopyTo(m.data, 0);
            return m;
        }

        /**
         */
        public override string ToString() { 
            string s = "Matrix{\n";
            for(int i = 0; i < nRows; i ++) {
                s += "\t";
                for(int j = 0; j < nCols; j ++) {
                    if(j > 0) {
                        s += "  ";   
                    }
                    s += this[i,j];
                    
                }
                s += "\n";
            }
            s += "}\n";
            return s;
        }

        // Static
        //единичной
        public static Matrix GetUnity(int Size) {
            Matrix m =  new Matrix(Size,Size);
            for(int i = 0; i < Size; i ++) {
                m[i,i] = 1;
            }
            return m;
        }

        public static Matrix GetEmpty(int Size) {
            return new Matrix(Size,Size);
        }


        public static Matrix Parse(string s) {
            if(s.Length == 0) {
                throw new FormatException("");
            }
            string[] rows = s.Split(",");
            Matrix m = new Matrix(rows.Length, rows[0].Trim().Split(" ").Length);
            for(int i = 0; i < m.nRows; i ++) {
                string[] cols = rows[i].Trim().Split(" ");
                for(int j = 0; j < m.nCols; j ++) {
                    int n;
                    if(! int.TryParse(cols[j], out n)) {
                        n = 0;
                    }
                    m[i,j] = n;
                }
            }
            return m;
        }

        public static bool TryParse(string s, out Matrix m){
            if(s.Length == 0) {
                m = null;
                return false;
            }
            string[] rows = s.Split(",");
            m = new Matrix(rows.Length, rows[0].Trim().Split(" ").Length);
            for(int i = 0; i < m.nRows; i ++) {
                string[] cols = rows[i].Trim().Split(" ");
                for(int j = 0; j < m.nCols; j ++) {
                    int n;
                    if(! int.TryParse(cols[j], out n)) {
                        n = 0;
                    }
                    m[i,j] = n;
                }
            } 
            return true;
        }  
    }
}