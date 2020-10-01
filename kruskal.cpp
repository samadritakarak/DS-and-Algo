#include <bits/stdc++.h>
using namespace std;
struct structure
{
    int start;
    int end;
    int weight;
};
bool comapre(structure a, structure b)
{
    if (a.weight < b.weight)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int findParent(int current, int *parent)
{
    if (current == parent[current])
    {
        return current;
    }
    return findParent(parent[current], parent);
}
structure *MST(structure *arr, int e, int v)
{
    int *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    structure *result = new structure[v - 1];
    while (count < v - 1 && i < e)
    {
        structure current = arr[i];
        int first_parent = findParent(current.start, parent);
        int second_parent = findParent(current.end, parent);
        if (first_parent != second_parent)
        {
            result[count++] = current;
            parent[first_parent] = second_parent;
        }
        i++;
    }
    return result;
}
int main()
{
    int v, e;
    cin >> v >> e;
    structure *arr = new structure[e];
    for (int i = 0; i < e; i++)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].weight;
    }
    sort(arr, arr + e, comapre);
    structure *result = MST(arr, e, v);
    for (int i = 0; i < v - 1; i++)
    {
        if (result[i].start < result[i].end)
        {
            cout << result[i].start << " " << result[i].end << " " << result[i].weight << "\n";
        }
        else
        {
            cout << result[i].end << " " << result[i].start << " " << result[i].weight << "\n";
        }
    }
}