class Note {
  final int? id;
  final String title;
  final String description;
  final DateTime createdAt;
  Note({
    this.id,
    required this.title,
    required this.description,
    required this.createdAt,
  });

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'title': title,
      'description': description,
      'createdAt': createdAt.toIso8601String(),
    };
  }

  factory Note.fromMap(Map<String, dynamic> map) {
    final createdAt = map['createdAt'] ?? DateTime.now().toIso8601String();

    return Note(
      id: map['id'],
      title: map['title'],
      description: map['description'],
      createdAt: DateTime.parse(createdAt),
    );
  }
}
