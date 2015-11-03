<!DOCTYPE html>
<html lang="en">
  <head>
    <!-- Meta, title, CSS, favicons, etc. -->
    <meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">

<title>
    NOI Reference
</title>

<!-- Bootstrap core CSS -->
<link href="/css/bootstrap.min.css" rel="stylesheet">

<!-- Documentation extras -->
<link href="/css/docs.min.css" rel="stylesheet">
<link href="/css/prettify.css" rel="stylesheet">
<link href="/css/app.css" rel="stylesheet">
<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
<!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
  <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
<![endif]-->



  </head>
  <body>
    <a class="sr-only" href="#content">Skip to main content</a>

    <!-- Docs master nav -->
    <header class="navbar navbar-static-top bs-docs-nav" role="banner">
  <div class="container">
    <div class="navbar-header">
      <button class="navbar-toggle" type="button" data-toggle="collapse" data-target=".bs-navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
      <a href="/" class="navbar-brand">NOI Reference</a>
    </div>
    <nav class="collapse navbar-collapse bs-navbar-collapse" role="navigation">
      <ul class="nav navbar-nav">
        <li>
          <a href="/misc/">Misc.</a>
        </li>
        <li>
          <a href="/math/">Math</a>
        </li>
        <li>
          <a href="/dp/">Dynamic Programming</a>
        </li>
        <li>
          <a href="/graph/">Graph</a>
        </li>
        <li class="active">
          <a href="/ds/">Data Structure</a>
        </li>
      </ul>
    </nav>
  </div>
</header>


    <!-- Docs page layout -->
    <div class="bs-header" id="content">
      <div class="container">
        <h1>Data Structures</h1>
        <p>Custom Data Structures</p>
        
      </div>
    </div>

    <div class="container bs-docs-container">

      <div class="row">
        <div class="col-md-9" role="main">
<!-- Union Find Disjoint Set ================================================== -->
<div class="bs-docs-section">
  <h1 id="ufds" class="page-header">Union Find Disjoint Set</h1>
  <p>Union Find Disjoint Set (UFDS) is a data structure that allows you to quickly merge groups of elements and check which group an element is in. It does so by having a 'parent' for each element. The 'parent' of an element means that it is in the same group as the 'parent'.</p>
  <p>Initially, the 'parent' of each element is itself. This means that it is in its own group. To merge two elements, set the parent of one group to be the parent of the other.</p>
  <p>For each group, there is a leader (also known as 'super parent'). The leader is the only element in the group that is the 'parent' of itself. All other elements will be the 'children' of this leader indirectly or directly. (Eg: the leader can be the 'parent' of the 'parent' of an element) Thus, the leader of an element can be found via recursion easily.</p>
  <h3 id="ufds-compress">Path Compression</h3>
  <p>In order to speed up the leader finding process, we save the leader as the 'parent' of the element whenever a query for the leader of the element is requested. The following code is a UFDS implementation for N elements labelled 0 to N-1:</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/ufds.cpp")); ?></pre>


</div>
    </div>
        <div class="col-md-3">
          <div class="bs-sidebar hidden-print" role="complementary">
            <ul class="nav bs-sidenav">
              
<li>
  <a href="#tips">Tips</a>
  <ul class="nav">
    <li><a href="#tips-header">Header Files</a></li>
    <li><a href="#tips-define">Define</a></li>
    <li><a href="#tips-iterators">Iterators</a></li>
    <li><a href="#tips-typedef">Typedef</a></li>
    <li><a href="#tips-typeof">Typeof</a></li>
  </ul>
</li>

<li>
  <a href="#bits">Bit Manipulation</a>
  <ul class="nav">
    <li><a href="#bits-basic">Basic Operations</a></li>
    <li><a href="#bits-bitmask">Bitmask</a></li>
  </ul>
</li>



              
            </ul>
          </div>
        </div>
      </div>

    </div>

    <!-- Footer
================================================== -->
<footer class="bs-footer" role="contentinfo">
  <div class="container">
    <p>Code compiled and written by Ranald Lam.</p>
    <p>Copyrighted 2014. All rights reserved.</p>
    <p>Limited distribution among Raffles Institution students only.</p>
  </div>
</footer>

<!-- Bootstrap core JavaScript
================================================== -->
<!-- Placed at the end of the document so the pages load faster -->
<script src="/js/jquery.min.js"></script>
<script src="/js/bootstrap.min.js"></script>
<script src="/js/docs.min.js"></script>
<script src="/js/prettify.js"></script>
<script src="/js/app.js"></script>

  </body>
</html>
