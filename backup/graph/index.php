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
        <li class="active">
          <a href="/graph/">Graph</a>
        </li>
        <li>
          <a href="/ds/">Data Structure</a>
        </li>
      </ul>
    </nav>
  </div>
</header>


    <!-- Docs page layout -->
    <div class="bs-header" id="content">
      <div class="container">
        <h1>Graph Theory</h1>

      </div>
    </div>

    <div class="container bs-docs-container">

      <div class="row">
        <div class="col-md-9" role="main">
<!-- Depth First Search ================================================== -->
<div class="bs-docs-section">
  <h1 id="dfs" class="page-header">Depth First Search</h1>
  <h3 id="dfs-floodgrid">Flood Fill - Grid</h3>
  <p><code>H</code> and <code>W</code> is the height of the grid and the width of the grid respectively.</p>
  <p><code>grid[x][y]</code> stores the grid information for the cell (x, y) where 0 &le; x &lt; H and 0 &le; y &lt; W. A cell with 'X' will mean it is a restricted cell (cannot travel on it).</p>
  <p><code>visited[x][y]</code> indicates whether the cell (x, y) has been visited by DFS before</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/dfs_floodgrid.cpp")); ?></pre>
  
  <h3 id="dfs-floodadjlist">Flood Fill - Adj List</h3>
  <p>Nodes are labelled from 0 to <code>N-1</code> and <code>adjList[x]</code> stores the directed edges that points from node <code>x</code> to other notes.</p>
  <p><code>visited[x]</code> indicates whether the node <code>x</code> has been visited or not.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/dfs_floodadjlist.cpp")); ?></pre>
  
  
  <h3 id="dfs-topo">Topological Sort</h3>
  <p>Nodes are labelled from 0 to <code>N-1</code> and <code>adjList[x]</code> stores the directed edges that points from node <code>x</code> to other notes.</p>
  <p><code>visited[x]</code> indicates whether the node <code>x</code> has been visited or not.</p>
  <p>Topological order will be stored in vector <code>topo</code>.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/dfs_topo.cpp")); ?></pre>
  
  <h3 id="dfs-ssspontree">SSSP on Tree</h3>
  <p>Nodes are labelled from 0 to <code>N-1</code> and <code>adjList[x]</code> stores the directed edges that points from node <code>x</code> to other notes.</p>
  <p><code>S</code> will be the source of the algorithm. Distance from <code>S</code> to <code>X</code> will be located at <code>dist[X]</code>. A distance of -1 indicates that it is not possible to reach node <code>X</code> from <code>S</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/dfs_ssspontree.cpp")); ?></pre>
  
</div>

<!-- Breadth First Search ================================================== -->
<div class="bs-docs-section">
  <h1 id="bfs" class="page-header">Breadth First Search</h1>
  
  <h3 id="bfs-ssspgrid">SSSP - Grid</h3>
  <p>For BFS to work for SSSP, edge weights must be the same (or 1).</p>
  <p><code>H</code> and <code>W</code> is the height of the grid and the width of the grid respectively.</p>
  <p><code>grid[x][y]</code> stores the grid information for the cell (x, y) where 0 &le; x &lt; H and 0 &le; y &lt; W. A cell with 'X' will mean it is a restricted cell (cannot travel on it).</p>
  <p><code>dist[x][y]</code> indicates the distance from the start cell(sx, sy) to the cell (x, y). If it is -1, it means that cell (x, y) is not reachable from the start cell.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/bfs_ssspgrid.cpp")); ?></pre>
  
  <h3 id="bfs-ssspadjlist">SSSP - AdjList</h3>
  <p>For BFS to work for SSSP, edge weights must be the same (or 1).</p>
  <p>Nodes are labelled from 0 to <code>N-1</code> and <code>adjList[x]</code> stores the directed edges that points from node <code>x</code> to other notes.</p>
  <p><code>dist[x]</code> indicates the distance from the start node <code>S</code> to the node <code>x</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/bfs_sspadjlist.cpp")); ?></pre>
</div>

<!-- Floyd Warshall ================================================== -->
<div class="bs-docs-section">
  <h1 id="floyd" class="page-header">Floyd Warshall</h1>
  <p>The following floyd warshall code works for non-negative edge weights only.</p>
  <p>Nodes are labelled from 0 to <code>N-1</code> and <code>adjMat[x][y]</code> stores the edge weight from node <code>x</code> to node <code>y</code>. If there is no edge from node <code>x</code> to node <code>y</code>, set <code>adjMat[x][y]</code> to -1 instead.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/floyd.cpp")); ?></pre>
</div>

<!-- Shortest Path Faster Algorithm ================================================== -->
<div class="bs-docs-section">
  <h1 id="spfa" class="page-header">Shortest Path Faster Algorithm</h1>
  
  <h3 id="spfa-normal">Normal SPFA</h3>
  <p><b>Use this code only when the end isn't stated</b></p>
  <p>Nodes are labelled from 0 to <code>N-1</code> and <code>adjList[x]</code> stores the directed edges that points from node <code>x</code> to other notes.</p>
  <p>Source is defined as node <code>S</code>.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/spfa_normal.cpp")); ?></pre>
  
  <h3 id="spfa-prune">Pruned SPFA</h3>
  <p><b>Use this code only when the end is provided for significant pruning (lower runtime)</b></p>
  <p>Nodes are labelled from 0 to <code>N-1</code> and <code>adjList[x]</code> stores the directed edges that points from node <code>x</code> to other notes.</p>
  <p>Source is defined as node <code>S</code> and the End is defined as node <code>E</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/spfa_normal.cpp")); ?></pre>
</div>

    </div>
        <div class="col-md-3">
          <div class="bs-sidebar hidden-print" role="complementary">
            <ul class="nav bs-sidenav">
              
<li>
  <a href="#ufds">Union Find Disjoint Set</a>
  <ul class="nav">
    <li><a href="#ufds-compress">Path Compression</a></li>
    <li><a href="#ufds-rank">Union by Rank</a></li>
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
    <p>Site page views: <?php echo file_get_contents("../counter.txt"); ?></p>

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
<?php $counter = intval(file_get_contents("../counter.txt")); file_put_contents("../counter.txt", $counter+1); ?>

