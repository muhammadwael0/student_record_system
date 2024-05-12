# student record system

## Project Description
<p>This is a student record system project that simulate the working environment <br>
of a school database as it implements different operations on premade students database<br>
and premade admins database to organize multiple admins activities on students database.
</p>

## Project Layers

<ol>
<h3><li>UI LAYER</li></h3>
> <p>It's the display layer for the project that the user react with and <br>
> it uses the functions inside the <strong>APP layer</strong>.</p>
<h3><li>APPLICATION LAYER</li></h3>
> <p>It's the layer that connect the <strong>UI layer</strong> with the <strong>Data access layer</strong> <br>
> by using a set of intermediate functions that organize both layers and it accesses the <strong>Data access layer</strong> only.</p>
<h3><li>DATA ACCESS LAYER</li></h3>
> <p>It's the layer that control all data related operations as it deals with <br>
> the row data using a set of functions that all the functions of the <strong>APP layer</strong> <br>
> depend on to manipulate the data</p>
</ol>

## Project Folders & Files

<ul>
 <li>ui</li>
  <ul>
   <li>main.c</li>
   <li>main.h</li>
  </ul>
 <li>app</li>
  <ul>
   <li>admin</li>
    <ul>
     <li>admin.c</li>
     <li>admin.h</li>
    </ul>
   <li>authentication</li>
    <ul>
     <li>authentication.c</li>
     <li>authentication.h</li>
    </ul>
   <li>student</li>
    <ul>
     <li>student.c</li>
     <li>astudent.h</li>
    </ul>
  </ul>
 <li>data</li>
</ul>