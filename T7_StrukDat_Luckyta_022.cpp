#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

// Struktur node untuk binary tree
struct TreeNode {
    int val;            // nilai node
    TreeNode* left;     // pointer ke anak kiri
    TreeNode* right;    // pointer ke anak kanan

    // Constructor untuk inisialisasi node
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Fungsi untuk mencari kedalaman minimum (min depth) menggunakan BFS
int minDepth(TreeNode* root) {
    // Jika tree kosong, kedalaman = 0
    if (!root) return 0;

    // Queue untuk BFS (menyimpan node per level)
    queue<TreeNode*> q;
    q.push(root);

    int depth = 1; // mulai dari level root

    // Selama queue tidak kosong
    while (!q.empty()) {
        int size = q.size(); // jumlah node pada level saat ini

        // Loop untuk memproses semua node di level tersebut
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // Jika node adalah leaf (tidak punya anak)
            // maka ini adalah kedalaman minimum
            if (!node->left && !node->right)
                return depth;

            // Masukkan anak kiri ke queue jika ada
            if (node->left) q.push(node->left);

            // Masukkan anak kanan ke queue jika ada
            if (node->right) q.push(node->right);
        }

        // Setelah satu level selesai, naik ke level berikutnya
        depth++;
    }

    return depth; // fallback (seharusnya tidak sampai sini)
}

// Fungsi untuk membangun binary tree dari input array string
TreeNode* buildTree(vector<string>& nodes) {
    // Jika elemen pertama null, tree kosong
    if (nodes[0] == "null") return NULL;

    // Buat root dari elemen pertama
    TreeNode* root = new TreeNode(stoi(nodes[0]));

    // Queue untuk membantu membangun tree level-order
    queue<TreeNode*> q;
    q.push(root);

    int i = 1; // index untuk membaca array nodes

    // Selama queue tidak kosong dan masih ada data
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Jika bukan "null", buat anak kiri
        if (nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Jika masih ada elemen dan bukan "null", buat anak kanan
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    string input;

    // Input dalam format: 1,2,3,null,4
    cout << "Input: ";
    cin >> input;

    vector<string> nodes;
    stringstream ss(input);
    string temp;

    // Memisahkan input berdasarkan koma
    while (getline(ss, temp, ',')) {
        nodes.push_back(temp);
    }

    // Membangun tree dari input
    TreeNode* root = buildTree(nodes);

    // Menampilkan hasil kedalaman minimum
    cout << "Kedalaman Minimum: ";
    cout << minDepth(root) << endl;

    return 0;
}
