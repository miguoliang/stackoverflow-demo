#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

typedef vector<double> _MatrixRow;
typedef vector<_MatrixRow> Matrix;

// read a matrix from a given file
Matrix get_matrix(string filename);
// print a matrix
void print_matrix(const Matrix &matrix);
// multiplication of matrices
Matrix matrix_multiply(const Matrix &left, const Matrix &right);

int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
        cerr << "USAGE: main <leftMatrixFilename> <rightMatrixFilename>" << endl;
        exit(-1);
    }

    string leftFilename(argv[1]);
    string rightFilename(argv[2]);

    Matrix left = get_matrix(leftFilename);
    Matrix right = get_matrix(rightFilename);

    cout << "Left matrix: " << endl
         << "=====" << endl;
    print_matrix(left);

    cout << "Right matrix: " << endl
         << "=====" << endl;
    print_matrix(right);

    Matrix matrix = matrix_multiply(left, right);

    cout << "Result matrix: " << endl
         << "=====" << endl;
    print_matrix(matrix);

    return 0;
}

Matrix get_matrix(string filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cerr << filename << " does not exist." << endl;
        exit(-1);
    }

    Matrix matrix;

    string line;
    cout << "Reading file: " << filename << endl
         << "=====" << endl;
    while (!infile.eof())
    {
        getline(infile, line);
        cout << line << endl;

        string token;
        size_t pos = 0;
        string delimiter = ",";
        _MatrixRow cells;
        while ((pos = line.find(delimiter, pos) != string::npos))
        {
            token = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            cells.push_back(atof(token.data()));
        }
        cells.push_back(atof(line.data()));
        matrix.push_back(cells);
    }
    infile.close();
    cout << endl;

    return matrix;
}

void print_matrix(const Matrix &matrix)
{
    Matrix::const_iterator iter;
    for (iter = matrix.begin(); iter != matrix.end(); iter++)
    {
        _MatrixRow cells = *iter;
        _MatrixRow::const_iterator cellIter;
        cellIter = (*iter).begin();
        while (cellIter != (*iter).end())
        {
            if (cellIter != (*iter).begin())
            {
                cout << ",";
            }
            cout << *cellIter++;
        }
        cout << endl;
    }
    cout << endl;
}

Matrix matrix_multiply(const Matrix &left, const Matrix &right)
{
    // Validate conditions of multiplication of matrices
    if (left.empty())
    {
        cerr << "Left matrix is empty." << endl;
        exit(-1);
    }

    if (right.empty())
    {
        cerr << "Right matrix is empty." << endl;
        exit(-1);
    }

    const int leftRowCount = left.size();
    const int leftColumnCount = left.front().size();

    const int rightRowCount = right.size();
    const int rightColumnCount = right.front().size();

    if (leftColumnCount != rightRowCount)
    {
        cerr << "The number of columns of the left matrix is not the same as the number of columns of the right matrix." << endl;
        exit(-1);
    }

    cout << "Calculate steps" << endl
         << "=====" << endl;

    // Calculation
    Matrix matrix(leftRowCount);
    for (int i = 0; i < leftRowCount; i++)
    {
        matrix.at(i).resize(rightColumnCount);
        for (int j = 0; j < rightColumnCount; j++)
        {
            matrix.at(i).at(j) = 0;
            cout << "M(" << i << "," << j << ") = ";
            for (int k = 0; k < leftColumnCount; k++)
            {
                cout << "L(" << i << "," << k << ") + R(" << k << "," << j << ")";
                if (k < leftColumnCount - 1)
                {
                    cout << " + ";
                }
                matrix.at(i).at(j) += left.at(i).at(k) * right.at(k).at(j);
            }
            cout << endl;
        }
    }

    cout << endl;

    return matrix;
}