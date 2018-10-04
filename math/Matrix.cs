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

        public int Size { 
            get {
                return nCols * nRows;
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
                        //TODO
                    }
                }

                return true;
            } 
        }

        // OPERATORS

        public static Matrix operator+(Matrix m1,Matrix m2) {
            return m1;
        }

        public static Matrix operator-(Matrix m1, Matrix m2) {
            return m1;
        }

        public static Matrix operator*(Matrix m1, double d) {
            return m1;
        }

        public static Matrix operator*(Matrix m1, Matrix m2) {
            return m1;
        }
 
        public static explicit operator Matrix(double[,] arr) {
            return new Matrix(1,1);
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
            return this;
         }

        // вычисления следа матрицы
        public double Trace() {
            return 0.0;
        }

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
        public static Matrix GetUnity(int Size) {
            return new Matrix(0,0);
        }

        public static Matrix GetEmpty(int Size) {
            return new Matrix(0,0);
        }


        public static Matrix Parse(string s) {
            if(s.Length == 0) {
                throw new FormatException("");
            }
            return new Matrix(0,0);
        }

        public static bool TryParse(string s, out Matrix m){
            m = new Matrix(0,0);
            return false;
        } 

    }
}