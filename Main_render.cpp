#include "shader_util.cpp"

GLuint shaderProgram, ID;
GLuint cube_vao, cube_vbo;

void initCubes()
{
  std::vector<float> C = {0.8f,0.5f,0.5f};
  change_cube_state(10,10,10, C);
}

void initShadersGL(void)
{
  std::string vertex_shader_file("simple_vs.glsl");
  std::string fragment_shader_file("simple_fs.glsl");

  std::vector<GLuint> shaderList;
  shaderList.push_back(csX75::LoadShaderGL(GL_VERTEX_SHADER, vertex_shader_file));
  shaderList.push_back(csX75::LoadShaderGL(GL_FRAGMENT_SHADER, fragment_shader_file));

  shaderProgram = csX75::CreateProgramGL(shaderList);

  /* glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.5f, 4.0f);
  unsigned int transformLoc = glGetUniformLocation(shaderProgram, "projection");
  glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(projection)); */

}

void initVertexBufferGL(void)
{
  //Ask GL for a Vertex Attribute Object (vao)
  glGenVertexArrays (1, &cube_vao);
  //Set it as the current array to be used by binding it
  glBindVertexArray (cube_vao);
  //Enable the vertex attribute

  glEnableVertexAttribArray (0);//vertex coordinates
  glEnableVertexAttribArray (1);//colors

  glGenBuffers (1, &cube_vbo);
  glBindBuffer (GL_ARRAY_BUFFER, cube_vbo);
  glBufferData (GL_ARRAY_BUFFER, sizeof(vertex_data), &vertex_data[0], GL_STATIC_DRAW);

  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), NULL);
  glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));

  for(int i = 0; i < 36*6; i++)
  {
    std::cout << vertex_data[i] << " ";
    if(i % 6 == 5)
      std:: cout << "\n";
  }
}

void renderGL(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glUseProgram(shaderProgram);

  glBindVertexArray (cube_vao);

  // Draw points 0-3 from the currently bound VAO with current in-use shader
  glDrawArrays(GL_TRIANGLES, 0, 36*6);
}

int main(int argc, char** argv)
{
  //! The pointer to the GLFW window
  GLFWwindow* window;

  //! Setting up the GLFW Error callback
  glfwSetErrorCallback(csX75::error_callback);

  //! Initialize GLFW
  if (!glfwInit())
    return -1;

  //We want OpenGL 4.0
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //This is for MacOSX - can be omitted otherwise
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
  //We don't want the old OpenGL 
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

  //! Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(640, 480, "CS475/CS675 OpenGL Framework", NULL, NULL);
  if (!window)
    {
      glfwTerminate();
      return -1;
    }
  
  //! Make the window's context current 
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
  }  

  //Print and see what context got enabled
  std::cout<<"Vendor: "<<glGetString (GL_VENDOR)<<std::endl;
  std::cout<<"Renderer: "<<glGetString (GL_RENDERER)<<std::endl;
  std::cout<<"Version: "<<glGetString (GL_VERSION)<<std::endl;
  std::cout<<"GLSL Version: "<<glGetString (GL_SHADING_LANGUAGE_VERSION)<<std::endl;

  //Keyboard Callback
  glfwSetKeyCallback(window, csX75::key_callback);
  //Framebuffer resize callback
  glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  //Initialize GL state
  csX75::initGL();
  initShadersGL();
  initCubes();
  initVertexBufferGL();
  /* for(int i = 0; i < 36*6; i++)
  {
    std::cout << vertex_data[i] << " ";
    if(i % 6 == 5)
      std:: cout << "\n";
  } */

  // Loop until the user closes the window
  while (glfwWindowShouldClose(window) == 0)
    {
       
      // Render here
      renderGL();

      // Swap front and back buffers
      glfwSwapBuffers(window);
      
      // Poll for and process events
      glfwPollEvents();
    }
  
  glfwTerminate();
  return 0;
}

