#ifndef ATG_SIMPLE_2D_CONSTRAINT_SOLVER_MATRIX_H
#define ATG_SIMPLE_2D_CONSTRAINT_SOLVER_MATRIX_H

#include <assert.h>

namespace atg_scs {
    class Matrix {
        public:
            Matrix();
            Matrix(int width, int height, double value = 0.0);
            ~Matrix();

            void initialize(int width, int height, double value = 0.0);
            void resize(int width, int height);
            void destroy();

            void set(const double *data);

            __forceinline void set(int column, int row, double value) {
                assert(column >= 0 && column < m_width);
                assert(row >= 0 && row < m_height);

                m_matrix[row][column] = value;
            }

            __forceinline double get(int column, int row) {
                assert(column >= 0 && column < m_width);
                assert(row >= 0 && row < m_height);

                return m_matrix[row][column];
            }

            void set(Matrix *reference);

            void multiply(Matrix &b, Matrix *target);
            void leftScale(Matrix &scale, Matrix *target);
            void rightScale(Matrix &scale, Matrix *target);
            void subtract(Matrix &b, Matrix *target);
            void negate(Matrix *target);

            void transpose(Matrix *target);
            int getWidth() const { return m_width; }
            int getHeight() const { return m_height; }

            void fastRowSwap(int a, int b);

        protected:
            double **m_matrix;
            double *m_data;
            int m_width;
            int m_height;
            int m_capacityWidth;
            int m_capacityHeight;
    };
} /* namespace atg_scs */

#endif /* ATG_SIMPLE_2D_CONSTRAINT_SOLVER_MATRIX_H */
