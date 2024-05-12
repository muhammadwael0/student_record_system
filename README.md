# student record system

## Project Description
<p>This is a student record system project that simulate the working environment <br>
of a school database as it implements different operations on premade students database<br>
and premade admins database to organize multiple admins activities on students database.
</p>

## Project Layers

<ol>
<li><h3>UI LAYER</h3></li>
> <p>It's the display layer for the project that the user react with and <br>
> it uses the functions inside the **APP layer**.</p>
<li><h3>APPLICATION LAYER</h3></li>
> <p>It's the layer that connect the **UI layer** with the **Data access layer** <br>
> by using a set of intermediate functions that organize both layers and it accesses the **Data access layer** only.</p>
<li><h3>DATA ACCESS LAYER</h3></li>
> <p>It's the layer that control all data related operations as it deals with <br>
> the row data using a set of functions that all the functions of the APP layer <br>
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