# student record system

## Project Description
<p>This is a student record system project that simulate the working environment <br>
of a school database as it implements different operations on premade students database<br>
and premade admins database to organize multiple admins activities on students database.
</p>

## Project Layers

<ol>
<h3><li>UI LAYER</li></h3>
<blockquote>
<p>It's the display layer for the project that the user react with and <br>
it uses the functions inside the <strong>APP layer</strong>.</p>
</blockquote>
<h3><li>APPLICATION LAYER</li></h3>
<blockquote>
<p>It's the layer that connect the <strong>UI layer</strong> with the <strong>Data access layer</strong>
by using a set of intermediate functions <br>that organize both layers and it accesses the <strong>Data access layer</strong> only.</p>
</blockquote>
<h3><li>DATA ACCESS LAYER</li></h3>
<blockquote>
<p>It's the layer that control all data related operations as it deals with the row data <br>
using a set of functions that all the functions of the <strong>APP layer</strong> <br>
depend on to manipulate the data.</p>
</blockquote>
</ol>

## Project Folders & Files

<ul>
 <h4><li>ui</li></h4>
  <ul>
   <li><em>main.c</em></li>
   <li><em>main.h</em></li>
  </ul>
 <h4><li>app</li></h4>
  <ul>
   <li><strong>admin</strong></li>
    <ul>
     <li><em>admin.c</em></li>
     <li><em>admin.h</em></li>
    </ul>
   <li><strong>authentication</strong></li>
    <ul>
     <li><em>authentication.c</em></li>
     <li><em>authentication.h</em></li>
    </ul>
   <li><strong>student</strong></li>
    <ul>
     <li><em>student.c</em></li>
     <li><em>astudent.h</em></li>
    </ul>
  </ul>
 <h4><li>data</li></h4>
  <ul>
   <li><strong>data_management</strong></li>
    <ul>
     <li><em>data_management.c</em></li>
     <li><em>data_management.h</em></li>
    </ul>
   <li><strong>file_access</strong></li>
    <ul>
     <li><em>file_access.c</em></li>
     <li><em>file_access.h</em></li>
    </ul>
   <li><strong>memory_management</strong></li>
    <ul>
     <li><em>memory_management.c</em></li>
     <li><em>memory_management.h</em></li>
    </ul>
   <li><em>std_lib.h</em></li>
  </ul>
</ul>

## Project Functions

<ul>
 <strong><li>main<br></li></strong>
 <h5> //* uses <strong>app layer</strong> functions *//</h5>
 <strong><li>admin</li></strong>
  <ul>
   <li>view_student_record</li>
   <li>edit_grade</li>
   <li>edit_password_of_admin</li>
   <li>view_all_records</li>
   <li>remove_student_record</li>
   <li>add_student_record</li>
  </ul>
 <strong><li>authentication</li></strong>
  <ul>
   <li>authenticate_admin</li>
   <li>authenticate_student_id</li>
   <li>authenticate_student_password</li>
  </ul>
 <strong><li>student</li></strong>
  <ul>
   <li>edit_name_of_student</li>
   <li>edit_password_of_student</li>
   <li>view_student_record_from_student</li>
  </ul>
 <strong><li>data_management</li></strong>
  <ul>
   <li>edit_record</li>
   <li>edit_admin_password</li>
   <li>edit_student_password</li>
   <li>edit_student_name</li>
  </ul>
 <strong><li>file_access</li></strong>
  <ul>
   <li>write_data_to_admins</li>
   <li>write_data_to_students</li>
   <li>write_data_to_records</li>
   <li>get_num_lines</li>
   <li>read_data_from_admins</li>
   <li>read_data_from_records</li>
   <li>read_data_from_students</li>
  </ul>
 <strong><li>memory_management</li></strong>
  <ul>
   <li>read_string_name</li>
   <li>read_string_password</li>
  </ul>
</ul>