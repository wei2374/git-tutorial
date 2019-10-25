# Merge Conflicts

When merging two branches there are sometimes changes that Git cannot automatically resolve. Git prefers then to flag the conflict as something it cannot resolve instead of intervening and potentially causing even larger errors. Errors that require human intervention usually result from changes to the same file, for example two people modify the same line of a file. Git would then require the person merging the files to decide which one it should keep.

It is important to note that during a merge process if you choose the wrong line or mess up the merge you can revert the merge. Meaning you must only commit the merge once you are happy that everything has been merged properly. At any time you can use the `git reset --hard HEAD` command to reset your HEAD to the last commit before the merge (if you didn't pick up on what this is then read [this](http://www.gitguys.com/topics/head-where-are-we-where-were-we/)).

## Resolving a conflict

When there is a merge conflict Git will tell you that there is unmerged paths and it will give you a list of the files involved. This can be found using `git status`.

``` bash
Unmerged paths:
  (use "git add <file>..." to mark resolution)

	both modified:   src/main.c
```

Inside each conflict file Git places markers that indicate the area of conflict. Let's take the simple example where two changes affected the same line of code in a file. This means that Git needs you to decide which change to keep. You will manually need to edit the code to integrate both solutions into your project. Choosing how to fix your code will be up to your discretion.

Now in this example I have branched my original code, then on the new branch **and** on my current branch created commits that modify the same line of code. On the current branch I added "Result:" to a `printf` statement while on the branch I added "Output:".

``` bash
Original code (shared commit) ------ + "Result:"
                              |----- + "Output:"
```

This has caused a merge conflict as the commit which they both share now has two different diffs when compared with the HEAD of both branches.

Looking into the file `src/main.c`, as shown by `git status`, we would see the following around the line of interest.

``` C
<<<<<<< HEAD                                                                     
        printf("Result: %s", tmp);                                               
=======                                                                          
        printf("Output: %s", tmp);                                               
>>>>>>> bar      
```

This tells use that on our current branch (our current HEAD) the line containing "Result", where as on the branch we wish to merge into our current branch (bar) the line contains "Output". Git does not know which one we wish to use and as such we must decide. Let's say that we wish the have the line contain output and not result, then we must manually delete the markers from Git as well as the line. Using our new patch knowledge we can see the what needs to be done below.

``` bash
--- src/main.c	2019-03-20 11:47:22.947753390 +0100
+++ src/main.c	2019-03-20 11:47:34.777753931 +0100
@@ -8,11 +8,7 @@
     char *tmp = NULL;
     tmp = num_to_words(123);
     if (tmp)
-<<<<<<< HEAD
-        printf("Result: %s", tmp);
-=======
         printf("Output: %s", tmp);
->>>>>>> bar
     else
         return 1;
    return 0;
```

Once you have resolved the merge conflict you can then add the resolved file and finalize the merge with a normal commit. The commit message should summarize the changes during the merge.

Now that you has seen the basic ideas of how merging works, lets see if you can handle some more complex merge problem yourself. You will find a branch called "unknown_features" which has diverged from this current branch at the previous commit. Your job now is to merge this branch into this current branch and resolve the conflicts presented. The project is a self-contained CMake project inside the `merge_exercise` folder and you will need to apply you C knowledge and CMake knowledge to merge the files correctly to get the project building properly. Once you have the project merged and building, merge the project into `merging` and finally into `master`, if both projects are stable and working as expected. Finally create another tag with the annotation "Exercise 1.2 Submission".

If all of that is done then you have completed this tutorial. Please be wary that the use of Git is a requirement in this course and will be part of the project's assessment. Inform yourself on proper use of Git commit messages and make sure that you and your team partner establish a Git workflow that you will use throughout the course. A fun tool to use to make sure your workflow has been used properly is `git log --graph --all` which will give you a graphical representation of your repo's logs.

# Future Reading

There are a number of other features in Git that are useful to know. If you are motivated then I would recommend reading up on these features so that during semester you are able to overcome some problems you will no doubt encounter.

 * `git stash`
 * `git pull`
 * `git show`
 * `git revert`
 * `git clean`
