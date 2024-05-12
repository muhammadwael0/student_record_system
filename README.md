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
depend on to manipulate the data</p>
</blockquote>
</ol>

## Project Folders & Files

<ul>
 <h4 style = "font-size: 25px"><li>ui</li></h4>
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