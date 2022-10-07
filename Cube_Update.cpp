#include"common.h"

std::vector<std::tuple<int,int,int,int>> present_faces;
//size 4 vectors: First int is the axis perpendicular to the face
//For the other 3, imagine the face centres as another grid, and 
//The XYZ coordinates of this new grid are the other 3 ints.

int IndexOf(std::tuple<int,int,int,int> face)
{
    int index = 0;
    for(;index < present_faces.size(); index++)
    {
        if(present_faces[index] == face)
            break;
    }
    return index;
}

void removeFace(int q)
{
    present_faces.erase(present_faces.begin() + q);
    vertex_data.erase(vertex_data.begin() + 36*q, vertex_data.begin() + 36*q + 36);
}

//will help in adding values to array
float increment = 2/(float(n));
void change_cube_state(int a, int b, int c, std::vector<float> &color)
{
    float vertices[6] = //will be incremented as needed
    {2*(a/float(n-1)) - 1.0f, 2*(b/float(n-1)) - 1.0f, 2*(c/float(n-1)) - 1.0f, color[0], color[1], color[2]};

    int q = IndexOf({0,a,b,c}); 
    if(q != present_faces.size())
        removeFace(q);
            
    else{
        present_faces.push_back({0,a,b,c});

        //triangle 1
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[2] += increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[1] += increment;       
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        //triangle 2
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[2] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[1] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
    }

    q = IndexOf({0,a+1,b,c}); 
    if(q != present_faces.size())
        removeFace(q);
            
    else{
        present_faces.push_back({0,a+1,b,c});

        vertices[0] += increment;
        //triangle 1
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[2] += increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[1] += increment;       
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        //triangle 2
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[2] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[1] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        vertices[0] -= increment;
    }

    q = IndexOf({1,a,b,c}); 
    if(q != present_faces.size())
        removeFace(q);
            
    else{
        present_faces.push_back({1,a,b,c});

        //triangle 1
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[2] += increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[0] += increment;       
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        //triangle 2
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[2] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[0] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
    }

    q = IndexOf({1,a,b+1,c}); 
    if(q != present_faces.size())
        removeFace(q);
            
    else{
        present_faces.push_back({1,a,b+1,c});

        vertices[1] += increment;
        //triangle 1
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[2] += increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[0] += increment;       
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        //triangle 2
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[2] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[0] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        vertices[1] -= increment;
    }

    q = IndexOf({2,a,b,c}); 
    if(q != present_faces.size())
        removeFace(q);
            
    else{
        present_faces.push_back({2,a,b,c});

        //triangle 1
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[1] += increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[0] += increment;       
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        //triangle 2
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[1] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[0] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
    }

    q = IndexOf({2,a,b,c+1}); 
    if(q != present_faces.size())
        removeFace(q);
            
    else{
        present_faces.push_back({2,a,b,c+1});

        vertices[2] += increment;
        //triangle 1
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[1] += increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[0] += increment;       
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        //triangle 2
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[1] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));
        vertices[0] -= increment;
        vertex_data.insert(vertex_data.end(), std::begin(vertices), std::end(vertices));

        vertices[2] =- increment;
    }
}