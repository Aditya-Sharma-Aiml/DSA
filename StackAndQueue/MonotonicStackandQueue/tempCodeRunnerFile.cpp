ctor<int> nums = {4, 5, 2, 10};
    Solution1 sol1;
    vector<int> ans = sol1.nextGreater(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << e