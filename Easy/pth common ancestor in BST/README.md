<h2><a href="https://practice.geeksforgeeks.org/problems/pth-common-ancestor-in-bst/1?page=2&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Binary%20Search%20Tree&sortBy=submissions">pth common ancestor in BST</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:20px">Given a Binary Search Tree and two node values x and y&nbsp;present in the BST. Your task is to find the pth</span><span style="font-size:20px">&nbsp;(p &gt;= 1) common ancestor of these two nodes x and y.</span></p>

<p><span style="font-size:20px">The 1st common ancestor is the lowest common ancestor. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).</span></p>

<p><span style="font-size:20px">All the elements of BST are non-negative and there is no duplicate entry in BST. Also,&nbsp;x and y are&nbsp;unequal.</span></p>

<p><span style="font-size:20px">You are required to complete the function <strong>pthCommonAncestor</strong><strong>()</strong>.</span></p>

<p><span style="font-size:20px">Return -1 if the pth common ancestor doesnt exist for a given BST.</span></p>

<p><span style="font-size:20px"><strong>Note:</strong> The <strong>Input/</strong><strong>Ouput</strong> format and <strong>Example</strong> given are used for system's internal purpose, and should be used by a user for <strong>Expected Output</strong> only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</span><br>
&nbsp;</p>

<p><span style="font-size:20px"><strong>Input:</strong></span></p>

<p><span style="font-size:20px">The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines. The first line of each test case consists of two integers N and p, denoting the number of elements in the BST and the p<sup>th</sup> common ancestor to be found, respectively. The second line of each test case consists of N space-separated integers denoting the elements in the BST. The third line of each test case consists of two integers x and y as described in the problem statement. </span></p>

<p><br>
<span style="font-size:20px"><strong>Output:</strong></span></p>

<p><span style="font-size:20px">You are required to complete the function <strong>pthCommonAncestor()&nbsp;</strong>which takes the root of the tree and two integers x and y(as described in the problem statement) as the arguments. The function returns the value of&nbsp;p<sup>th</sup> common ancestor to be found.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:20px"><strong>Constraints:</strong></span></p>

<p>&nbsp;</p>

<p><span style="font-size:20px">1 &lt;= T &lt;= 1000</span></p>

<p><span style="font-size:20px">2 &lt;= N &lt;= 1000</span></p>

<p><span style="font-size:20px">1 &lt;= p &lt;= 100</span></p>

<p><br>
<span style="font-size:20px"><strong>Example:</strong></span></p>

<p><span style="font-size:20px"><strong>Input:</strong></span></p>

<p><span style="font-size:20px">2</span></p>

<p><span style="font-size:20px">6 2</span></p>

<p><span style="font-size:20px">50 30 70 60 55 65</span></p>

<p><span style="font-size:20px">55 65</span></p>

<p><span style="font-size:20px">5 2</span></p>

<p><span style="font-size:20px">6 3 8 1 4</span></p>

<p><span style="font-size:20px">1 4</span></p>

<p><span style="font-size:20px"><strong>Output:</strong></span></p>

<p><span style="font-size:20px">70</span></p>

<p><span style="font-size:20px">6</span></p>

<p><span style="font-size:20px"><strong>Explanation:</strong></span></p>

<p><span style="font-size:20px">The BST for the <strong>sample test case 1</strong> is-</span></p>

<p><span style="font-size:20px">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;50 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// 50 is the 3rd common ancestor of 55 and 65</span></p>

<p><span style="font-size:20px">&nbsp; &nbsp; &nbsp; &nbsp; / &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;\</span></p>

<p><span style="font-size:20px">&nbsp;&nbsp; 30 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;70 &nbsp; &nbsp; // 70 is the 2nd common ancestor of 55 and 65</span></p>

<p><span style="font-size:20px">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/</span></p>

<p><span style="font-size:20px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;60 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// 60 is the 1st common ancestor of 55 and 65</span></p>

<p><span style="font-size:20px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \&nbsp;&nbsp;&nbsp;</span></p>

<p><span style="font-size:20px">&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;55&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 65</span></p>

<p><span style="font-size:20px">Hence, the value of 2nd common ancestor of 55 and 65 is 70.</span></p>

<p><span style="font-size:20px">The BST for the <strong>sample test case 2</strong> is-</span></p>

<p><span style="font-size:20px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 6 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// 6 is the 2nd common ancestor of 1 and 4</span></p>

<p><span style="font-size:20px">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; / &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;\</span></p>

<p><span style="font-size:20px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; // 3 is the 1st common ancestor of 1 and 4</span></p>

<p><span style="font-size:20px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; / &nbsp; &nbsp; &nbsp; &nbsp; \</span></p>

<p><span style="font-size:20px">&nbsp;&nbsp; 1 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4</span></p>

<p><span style="font-size:20px">Hence, the value of 2nd common ancestor of 1 and 4 is 6.</span></p>

<p>&nbsp;</p>

<p>&nbsp;</p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;